#include "VolumeVisualisation.h"

#include <fstream>
#include <iostream>
#include <vector>

#include <math.h>

#include "gris/mc_look_up.h"


int calculateIndex(const glm::ivec3& grid_position, const glm::ivec3& dimensions) {
    assert(grid_position.x < dimensions.x);
    assert(grid_position.y < dimensions.y);
    assert(grid_position.z < dimensions.z);
    return grid_position.x + grid_position.y * dimensions.x + grid_position.z * dimensions.x * dimensions.y;
};

VolumeVisualisation::VolumeVisualisation(const gris::BoundingBox& bounding_box):
    m_bounding_box(bounding_box) {
}

void VolumeVisualisation::generateTriviateVolumeData(const glm::ivec3& dimensions, const gris::BoundingBox& bounding_box) {
    assert(dimensions.x >= 2);
    assert(dimensions.y >= 2);
    assert(dimensions.z >= 2);

    m_is_trivariate = true;
    m_bounding_box = bounding_box;

    m_volume_data.dimensions = dimensions;

    const size_t voxelCount = static_cast<size_t>(dimensions.x) * static_cast<size_t>(dimensions.y) * static_cast<size_t>(dimensions.z);

    m_volume_data.values.resize(voxelCount);

    // Implementing Barth's sextic

    // Initializing golden ratio constant
    
    double tau = 0.5*(1.0+ sqrt(5.0));
    double tau_2 = pow(tau, 2.0);

    // Calculating half of the dimensions for normalization

    double half_x = static_cast<double>(m_volume_data.dimensions.x) * 0.5;
    double half_y = static_cast<double>(m_volume_data.dimensions.y) * 0.5;
    double half_z = static_cast<double>(m_volume_data.dimensions.z) * 0.5;

    // Implementing a scaling factor for better visualization afer normalization
    
    float scale_factor = 8.0f /std::max(m_volume_data.dimensions.x, std::max(m_volume_data.dimensions.y, m_volume_data.dimensions.z));
    
    // Iterating over voxels

    for (int i = 0; i < m_volume_data.dimensions.x; i++)
    {
        for (int j = 0; j < m_volume_data.dimensions.y; j++)
        {
            for (int k = 0; k < m_volume_data.dimensions.z; k++)
            {
                // Calculating current x, y, z after accounting for negative coordinates

                double x = static_cast<double>(i) - half_x;
                double y = static_cast<double>(j) - half_y;
                double z = static_cast<double>(k) - half_z;

                // Applying scaling factor
                x *= scale_factor;
                y *= scale_factor;
                z *= scale_factor;

                // Calculating powers for each coordinate
                double x_2 = x*x;
                double y_2 = y*y;
                double z_2 = z*z;
                double r = (x_2 + y_2 + z_2 - 1.0);


                // Calculating point value using Barth's sextic formula
                double point = 4*(tau_2*x_2 - y_2)*(tau_2*y_2 - z_2)*(tau_2*z_2 - x_2) - (1.0 + 2.0*tau)*r*r;

                // Storing point value in volume data
                m_volume_data.values[calculateIndex(glm::ivec3(i,j,k), m_volume_data.dimensions)] = point;
            }
        }
    }
}

void VolumeVisualisation::loadRawVolumeData(const std::string& path, const glm::ivec3& dimensions, const gris::BoundingBox& bounding_box) {
    assert(dimensions.x >= 2);
    assert(dimensions.y >= 2);
    assert(dimensions.z >= 2);

    m_is_trivariate = false;
    m_bounding_box = bounding_box;

    std::ifstream in(path, std::ios_base::in | std::ios_base::binary);

    if (in.is_open()) {
        std::cout << "Successfully opened file: " << path << std::endl;
    } else {
        std::cerr << "Failed to open file: " << path << std::endl;
    }

    m_volume_data.dimensions = dimensions;
    m_volume_data.values.resize(dimensions.x * dimensions.y * dimensions.z);

    // we know the bit depth (8 bits by now), so all that's left is to cast each char to a float between [0,1)
    for(int i = 0; i < dimensions.x * dimensions.y * dimensions.z; ++i) {
        float v = static_cast<unsigned char>(in.get()) / 256.0f;
        ;
        m_volume_data.values[i] = v;
    }
}

void VolumeVisualisation::generateMesh(float iso_value, bool dual, bool grid_snapping, float grid_snapping_distance, bool optimize_mesh) {
    m_iso_value = iso_value;

    clock_t start = clock();
    std::cout << "Mesh Generation started ..." << std::endl;

    if(dual) {
        dualMarchingCubes();
    } else {
        marchingCubes();
    }

    clock_t stop = clock();
    std::cout << "Mesh Generation finised after " << static_cast<float>(stop - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    // TODO(4.5):
    /*
    if(grid_snapping) {
        start = clock();
        std::cout << "\nGrid Snapping started ..." << std::endl;

        snapToGrid(grid_snapping_distance);

        stop = clock();
        std::cout << "Grid Snapping finised after " << static_cast<float>(stop - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
    }

    if(optimize_mesh) {
        start = clock();
        std::cout << "\nMesh Optimization started ..." << std::endl;

        cleanUpTriangleSoup();

        stop = clock();
        std::cout << "Mesh Optimization finised after " << static_cast<float>(stop - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
    }
    */

    std::cout << "Resulting Mesh has: " << m_mesh.vertices.size() << " vertices, " << m_mesh.triangles.size() << " triangles.\n"
              << std::endl;
}

void VolumeVisualisation::drawMesh(QOpenGLFunctions_2_1* f) const {

    glm::vec4 color = {0.2f, 0.2f, 0.5f, 1.f};

    f->glBegin(GL_TRIANGLES);
    for (int i = 0; i < m_mesh.triangles.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int triangle_vertice_index = m_mesh.triangles[i][j];
            glm::vec3 triangle_vertice_value = m_mesh.vertices[triangle_vertice_index];
            glm::vec3 triangle_normal_value = m_mesh.normals[triangle_vertice_index];

            f->glColor3fv(&color.x);

            f->glNormal3fv(reinterpret_cast<const float*>(&triangle_normal_value));

            f->glVertex3fv(reinterpret_cast<const float*>(&triangle_vertice_value));

        }
    }
    f->glEnd();
}

void VolumeVisualisation::drawNormals(QOpenGLFunctions_2_1* f) const {

    float scale_factor = 0.05f;

    f->glBegin(GL_LINES);
    for (int i = 0; i < m_mesh.vertices.size(); i++)
    {
        glm::vec3 starting_point_value = m_mesh.vertices[i];
        glm::vec3 ending_point_value = m_mesh.normals[i];
        glm::vec3 normal_vector = starting_point_value + ending_point_value * scale_factor;

        f->glVertex3fv(reinterpret_cast<const float*>(&starting_point_value));
        f->glVertex3fv(reinterpret_cast<const float*>(&normal_vector));
    }
    f->glEnd();
}

void VolumeVisualisation::drawVolumeData(QOpenGLFunctions_2_1* f) const {
    glm::vec3 min = m_bounding_box.min;
    glm::vec3 delta = (m_bounding_box.max - m_bounding_box.min) /
        glm::vec3{
            static_cast<float>(m_volume_data.dimensions.x - 1),
            static_cast<float>(m_volume_data.dimensions.y - 1),
            static_cast<float>(m_volume_data.dimensions.z - 1),
        };
    float radius = glm::min(delta.x, glm::min(delta.y, delta.z)) / 4.f;
    f->glBegin(GL_POINTS);
    for(int x = 0; x < m_volume_data.dimensions.x; x++) {
        for(int y = 0; y < m_volume_data.dimensions.y; y++) {
            for(int z = 0; z < m_volume_data.dimensions.z; z++) {
                if(m_volume_data.values[calculateIndex({x, y, z}, m_volume_data.dimensions)] >= m_iso_value) {
                    glm::vec3 point = min + delta * glm::vec3{static_cast<float>(x), static_cast<float>(y), static_cast<float>(z)};
                    f->glVertex3fv(reinterpret_cast<const float*>(&point));
                }
            }
        }
    }
    f->glEnd();
}

gris::TriangleMesh VolumeVisualisation::poligonize(const gris::GridCell& grid_cell, float iso_value) {
    int index = 0;
    index |= (grid_cell.values[0] < iso_value ? gris::CORNER_0 : 0);
    index |= (grid_cell.values[1] < iso_value ? gris::CORNER_1 : 0);
    index |= (grid_cell.values[2] < iso_value ? gris::CORNER_2 : 0);
    index |= (grid_cell.values[3] < iso_value ? gris::CORNER_3 : 0);
    index |= (grid_cell.values[4] < iso_value ? gris::CORNER_4 : 0);
    index |= (grid_cell.values[5] < iso_value ? gris::CORNER_5 : 0);
    index |= (grid_cell.values[6] < iso_value ? gris::CORNER_6 : 0);
    index |= (grid_cell.values[7] < iso_value ? gris::CORNER_7 : 0);
    const glm::ivec3* triangles = gris::triangle_table[index];
    gris::TriangleMesh result;

    for(int i = 0; i < 5; i++) {
        if(triangles[i].x == -1) {
            break;
        }
        const glm::ivec3 triangle = triangles[i];
        result.triangles.push_back({
            result.vertices.size(),
            result.vertices.size() + 1,
            result.vertices.size() + 2,
        });
        for(int edge : {triangle.x, triangle.y, triangle.z}) {
            float value_a;
            glm::vec3 corner_a;
            float value_b;
            glm::vec3 corner_b;
            switch(edge) {
            case gris::EDGE_0:
                value_a = grid_cell.values[0];
                corner_a = {grid_cell.volume.min.x, grid_cell.volume.min.y, grid_cell.volume.min.z};
                value_b = grid_cell.values[1];
                corner_b = {grid_cell.volume.max.x, grid_cell.volume.min.y, grid_cell.volume.min.z};
                break;
            case gris::EDGE_1:
                value_a = grid_cell.values[1];
                corner_a = {grid_cell.volume.max.x, grid_cell.volume.min.y, grid_cell.volume.min.z};
                value_b = grid_cell.values[2];
                corner_b = {grid_cell.volume.max.x, grid_cell.volume.min.y, grid_cell.volume.max.z};
                break;
            case gris::EDGE_2:
                value_a = grid_cell.values[2];
                corner_a = {grid_cell.volume.max.x, grid_cell.volume.min.y, grid_cell.volume.max.z};
                value_b = grid_cell.values[3];
                corner_b = {grid_cell.volume.min.x, grid_cell.volume.min.y, grid_cell.volume.max.z};
                break;
            case gris::EDGE_3:
                value_a = grid_cell.values[0];
                corner_a = {grid_cell.volume.min.x, grid_cell.volume.min.y, grid_cell.volume.min.z};
                value_b = grid_cell.values[3];
                corner_b = {grid_cell.volume.min.x, grid_cell.volume.min.y, grid_cell.volume.max.z};
                break;
            case gris::EDGE_4:
                value_a = grid_cell.values[4];
                corner_a = {grid_cell.volume.min.x, grid_cell.volume.max.y, grid_cell.volume.min.z};
                value_b = grid_cell.values[5];
                corner_b = {grid_cell.volume.max.x, grid_cell.volume.max.y, grid_cell.volume.min.z};
                break;
            case gris::EDGE_5:
                value_a = grid_cell.values[5];
                corner_a = {grid_cell.volume.max.x, grid_cell.volume.max.y, grid_cell.volume.min.z};
                value_b = grid_cell.values[6];
                corner_b = {grid_cell.volume.max.x, grid_cell.volume.max.y, grid_cell.volume.max.z};
                break;
            case gris::EDGE_6:
                value_a = grid_cell.values[6];
                corner_a = {grid_cell.volume.max.x, grid_cell.volume.max.y, grid_cell.volume.max.z};
                value_b = grid_cell.values[7];
                corner_b = {grid_cell.volume.min.x, grid_cell.volume.max.y, grid_cell.volume.max.z};
                break;
            case gris::EDGE_7:
                value_a = grid_cell.values[4];
                corner_a = {grid_cell.volume.min.x, grid_cell.volume.max.y, grid_cell.volume.min.z};
                value_b = grid_cell.values[7];
                corner_b = {grid_cell.volume.min.x, grid_cell.volume.max.y, grid_cell.volume.max.z};
                break;
            case gris::EDGE_8:
                value_a = grid_cell.values[0];
                corner_a = {grid_cell.volume.min.x, grid_cell.volume.min.y, grid_cell.volume.min.z};
                value_b = grid_cell.values[4];
                corner_b = {grid_cell.volume.min.x, grid_cell.volume.max.y, grid_cell.volume.min.z};
                break;
            case gris::EDGE_9:
                value_a = grid_cell.values[1];
                corner_a = {grid_cell.volume.max.x, grid_cell.volume.min.y, grid_cell.volume.min.z};
                value_b = grid_cell.values[5];
                corner_b = {grid_cell.volume.max.x, grid_cell.volume.max.y, grid_cell.volume.min.z};
                break;
            case gris::EDGE_10:
                value_a = grid_cell.values[2];
                corner_a = {grid_cell.volume.max.x, grid_cell.volume.min.y, grid_cell.volume.max.z};
                value_b = grid_cell.values[6];
                corner_b = {grid_cell.volume.max.x, grid_cell.volume.max.y, grid_cell.volume.max.z};
                break;
            case gris::EDGE_11:
                value_a = grid_cell.values[3];
                corner_a = {grid_cell.volume.min.x, grid_cell.volume.min.y, grid_cell.volume.max.z};
                value_b = grid_cell.values[7];
                corner_b = {grid_cell.volume.min.x, grid_cell.volume.max.y, grid_cell.volume.max.z};
                break;
            default:
                assert(false);
            }
            result.vertices.push_back(glm::mix(corner_a, corner_b, (value_a - iso_value) / (value_a - value_b)));
        }
    }
    return result;
}

void VolumeVisualisation::marchingCubes() {
    m_mesh.vertices.clear();
    m_mesh.normals.clear();
    m_mesh.triangles.clear();

    // Calculate size of cell for bounding box later

    glm::vec3 size_of_cell = (m_bounding_box.max - m_bounding_box.min) / glm::vec3((m_volume_data.dimensions - glm::ivec3(1.0,1.0,1.0)));

    // Variable for keeping track of vertices offset

    glm::ivec3 vertices_size = glm::ivec3(m_mesh.vertices.size());


    // Iterate from (0,0,0) to (n-2,n-2,n-2) for n - 1 cells between n points 

    for (int x = 0; x <= m_volume_data.dimensions.x - 2; x++)
    {
        for (int y = 0; y <= m_volume_data.dimensions.y - 2; y++)
        {
            for (int z = 0; z <= m_volume_data.dimensions.z - 2; z++)
            {

                //Construct current cell using points and bounding box
                gris::GridCell current_cell;

                current_cell.values[0] = m_volume_data.values[calculateIndex(glm::ivec3(x,y,z), m_volume_data.dimensions)];
                current_cell.values[1] = m_volume_data.values[calculateIndex(glm::ivec3(x+1,y,z), m_volume_data.dimensions)];
                current_cell.values[2] = m_volume_data.values[calculateIndex(glm::ivec3(x+1,y,z+1), m_volume_data.dimensions)];
                current_cell.values[3] = m_volume_data.values[calculateIndex(glm::ivec3(x,y,z+1), m_volume_data.dimensions)];
                current_cell.values[4] = m_volume_data.values[calculateIndex(glm::ivec3(x,y+1,z), m_volume_data.dimensions)];
                current_cell.values[5] = m_volume_data.values[calculateIndex(glm::ivec3(x+1,y+1,z), m_volume_data.dimensions)];
                current_cell.values[6] = m_volume_data.values[calculateIndex(glm::ivec3(x+1,y+1,z+1), m_volume_data.dimensions)];
                current_cell.values[7] = m_volume_data.values[calculateIndex(glm::ivec3(x,y+1,z+1), m_volume_data.dimensions)];

                current_cell.volume.min = m_bounding_box.min + (glm::vec3(x,y,z) * size_of_cell);
                current_cell.volume.max = m_bounding_box.min + (glm::vec3(x+1,y+1,z+1) * size_of_cell);

                gris::TriangleMesh current_mesh = poligonize(current_cell, m_iso_value);
                
                // Add current mesh to total mesh while keeping track of vertices offset for triangles
                vertices_size = glm::ivec3(m_mesh.vertices.size());

                for(int i = current_mesh.vertices.size() - 1; i >= 0; i--)
                {
                    m_mesh.vertices.push_back(current_mesh.vertices[i]);
                }

                for(int i = current_mesh.triangles.size() - 1; i >= 0 ; i--)
                {
                    m_mesh.triangles.push_back(current_mesh.triangles[i] + vertices_size);
                }
            }
        }

    }

    // Checking if trivariate or not using cout
    std::cout << "Is trivariate: " << m_is_trivariate << "\n\n";

    // Calculating normals based on the dataset

    if (m_is_trivariate) {
        // Using analytic gradient

        // Initializing golden ratio constant
    
        double tau = 0.5*(1.0+ sqrt(5.0));
        double tau_2 = pow(tau, 2.0);

        // Calculating half of the dimensions for normalization

        double half_x = static_cast<double>(m_volume_data.dimensions.x) * 0.5;
        double half_y = static_cast<double>(m_volume_data.dimensions.y) * 0.5;
        double half_z = static_cast<double>(m_volume_data.dimensions.z) * 0.5;

        // Implementing a scaling factor for better visualization afer normalization
        
        float scale_factor = 8.0f /std::max(m_volume_data.dimensions.x, std::max(m_volume_data.dimensions.y, m_volume_data.dimensions.z));
        
        // Iterating over vertices

        for (int i = 0; i < m_mesh.vertices.size(); i++)
        {
            // Converting current vertex in world space back to volume data space
            glm::vec3 transformed_vertex = ((m_mesh.vertices[i] - m_bounding_box.min)/(m_bounding_box.max - m_bounding_box.min)) * glm::vec3(m_volume_data.dimensions - glm::ivec3(1.0,1.0,1.0));

            // Extracting x, y, z coordinates
            double x = static_cast<double>(transformed_vertex.x);
            double y = static_cast<double>(transformed_vertex.y);
            double z = static_cast<double>(transformed_vertex.z);


            // Modifying current x, y, z to account for negative coordinates
            x -= half_x;
            y -= half_y;
            z -= half_z;

            // Applying scaling factor
            x *= scale_factor;
            y *= scale_factor;
            z *= scale_factor;

            // Calculating powers for each coordinate
            double x_2 = x*x;
            double y_2 = y*y;
            double z_2 = z*z;
            double r = (x_2 + y_2 + z_2 - 1.0);

            // Calculating partial derivatives for each coordinate based on Barth's sextic formula

            double partial_x = 8*tau_2*x*(tau_2*z_2 - x_2)*(tau_2*y_2 - z_2) - 8*x*(tau_2*x_2 - y_2)*(tau_2*y_2 - z_2) - 4*(1.0 + 2.0*tau)*x*r;
            double partial_y = 8*tau_2*y*(tau_2*x_2 - y_2)*(tau_2*z_2 - x_2) - 8*y*(tau_2*y_2 - z_2)*(tau_2*z_2 - x_2) - 4*(1.0 + 2.0*tau)*y*r;
            double partial_z = 8*tau_2*z*(tau_2*y_2 - z_2)*(tau_2*x_2 - y_2) - 8*z*(tau_2*z_2 - x_2)*(tau_2*x_2 - y_2) - 4*(1.0 + 2.0*tau)*z*r;

            // Storing normal in mesh normals
            m_mesh.normals.push_back(glm::normalize(-glm::vec3(partial_x, partial_y, partial_z)));
        }
    }
    else {
        // Using central finite differences

        // Iterating over vertices

        for (int i = 0; i < m_mesh.vertices.size(); i++)
        {
            // Converting current coordinate back to grid space
            glm::vec3 transformed_vertex = ((m_mesh.vertices[i] - m_bounding_box.min)/(m_bounding_box.max - m_bounding_box.min)) * glm::vec3(m_volume_data.dimensions - glm::ivec3(1.0,1.0,1.0));

            // Extracting x, y, z coordinates and converting to integers for indexing
            int x = static_cast<int>(transformed_vertex.x);
            int y = static_cast<int>(transformed_vertex.y);
            int z = static_cast<int>(transformed_vertex.z);

            // Clamping coordinates to be within the grid space
            x = std::max(1, std::min(x, m_volume_data.dimensions.x - 2));
            y = std::max(1, std::min(y, m_volume_data.dimensions.y - 2));
            z = std::max(1, std::min(z, m_volume_data.dimensions.z - 2));

            // Calculating indices

            int x_plus_1 = calculateIndex(glm::ivec3(x+1,y,z), m_volume_data.dimensions);
            int x_minus_1 = calculateIndex(glm::ivec3(x-1,y,z), m_volume_data.dimensions);
            int y_plus_1 = calculateIndex(glm::ivec3(x,y+1,z), m_volume_data.dimensions);
            int y_minus_1 = calculateIndex(glm::ivec3(x,y-1,z), m_volume_data.dimensions);
            int z_plus_1 = calculateIndex(glm::ivec3(x,y,z+1), m_volume_data.dimensions);
            int z_minus_1 = calculateIndex(glm::ivec3(x,y,z-1), m_volume_data.dimensions);

            // Calculating central finite differences for each coordinate
            double partial_x = ((m_volume_data.values[x_plus_1]) - (m_volume_data.values[x_minus_1])) / (2.0f * size_of_cell.x);
            double partial_y = ((m_volume_data.values[y_plus_1]) - (m_volume_data.values[y_minus_1])) / (2.0f * size_of_cell.y);
            double partial_z = ((m_volume_data.values[z_plus_1]) - (m_volume_data.values[z_minus_1])) / (2.0f * size_of_cell.z);

            // Storing normal in mesh normals
            m_mesh.normals.push_back(-glm::normalize(glm::vec3(partial_x, partial_y, partial_z)));
        }
    }
}

void VolumeVisualisation::dualMarchingCubes() {
    m_mesh.vertices.clear();
    m_mesh.normals.clear();
    m_mesh.triangles.clear();

    // Calculate size of cell for bounding box later

    glm::vec3 size_of_cell = (m_bounding_box.max - m_bounding_box.min) / glm::vec3((m_volume_data.dimensions - glm::ivec3(1.0,1.0,1.0)));

    // Defining object to store dual points

    struct CellDualPoints
    {
        int count = 0;
        int patchMask[4] = {0,0,0,0};
        int vertexIndex[4] = {-1,-1,-1,-1};
    };

    std::vector<CellDualPoints> dual_points((m_volume_data.dimensions.x-1)*(m_volume_data.dimensions.y-1)*(m_volume_data.dimensions.z-1));
    
    // Computing dual points for each cell
    
    for (int x = 0; x < m_volume_data.dimensions.x - 1; x++)
    {
        for (int y = 0; y < m_volume_data.dimensions.y - 1; y++)
        {
            for (int z = 0; z < m_volume_data.dimensions.z - 1; z++)
            {
                int index = 0;
                index |= (m_volume_data.values[calculateIndex(glm::ivec3(x,y,z), m_volume_data.dimensions)] < m_iso_value ? gris::CORNER_0 : 0);
                index |= (m_volume_data.values[calculateIndex(glm::ivec3(x+1,y,z), m_volume_data.dimensions)] < m_iso_value ? gris::CORNER_1 : 0);
                index |= (m_volume_data.values[calculateIndex(glm::ivec3(x+1,y,z+1), m_volume_data.dimensions)] < m_iso_value ? gris::CORNER_2 : 0);
                index |= (m_volume_data.values[calculateIndex(glm::ivec3(x,y,z+1), m_volume_data.dimensions)] < m_iso_value ? gris::CORNER_3 : 0);
                index |= (m_volume_data.values[calculateIndex(glm::ivec3(x,y+1,z), m_volume_data.dimensions)] < m_iso_value ? gris::CORNER_4 : 0);
                index |= (m_volume_data.values[calculateIndex(glm::ivec3(x+1,y+1,z), m_volume_data.dimensions)] < m_iso_value ? gris::CORNER_5 : 0);
                index |= (m_volume_data.values[calculateIndex(glm::ivec3(x+1,y+1,z+1), m_volume_data.dimensions)] < m_iso_value ? gris::CORNER_6 : 0);
                index |= (m_volume_data.values[calculateIndex(glm::ivec3(x,y+1,z+1), m_volume_data.dimensions)] < m_iso_value ? gris::CORNER_7 : 0);

                const int* dual_point_edges = gris::dual_points_list[index];

                int cell_index = x + ((m_volume_data.dimensions.x - 1) * y) + ((m_volume_data.dimensions.x - 1) * (m_volume_data.dimensions.y - 1) * z);
                CellDualPoints& cell = dual_points[cell_index];
                
                for (int i = 0; i < 4; i++)
                {
                    // Checking whether dual_point edge is current edge

                    int patch_mask = dual_point_edges[i];

                    // Ending if edges end

                    if (patch_mask == 0)
                    {
                        break;
                    }

                    // Computing dual point

                    glm::vec3 dual_point(0.0f);

                    int numIntersections = 0;

                    for (int edge = 0; edge < 12; edge++)
                    {
                        int edgeBit = (1 << edge);

                        if (patch_mask & edgeBit)
                        {
                            glm::vec3 intersection = computeEdgeIntersection(x, y, z, edge);
                            dual_point += intersection;
                            numIntersections++;
                        }

                    }

                    dual_point /= float(numIntersections);

                    int vertex_index = m_mesh.vertices.size();

                    // Adding computed dual point to mesh and storing in data structure for triangles later

                    m_mesh.vertices.push_back(dual_point);

                    cell.patchMask[cell.count] = patch_mask;
                    cell.vertexIndex[cell.count] = vertex_index;
                    cell.count++;
                }
            }
        }
    }

    // Computing triangles edge wise from dual points

    // Iterating over edges in x direction

    for (int x = 0; x < m_volume_data.dimensions.x - 1; x++)
    {
        for (int y = 0; y < m_volume_data.dimensions.y; y++)
        {
            for (int z = 0; z < m_volume_data.dimensions.z; z++)
            {
                // Checking if edge has transition of isovalue

                float value_a = m_volume_data.values[calculateIndex(glm::ivec3(x,y,z), m_volume_data.dimensions)];
                float value_b = m_volume_data.values[calculateIndex(glm::ivec3(x+1,y,z), m_volume_data.dimensions)];

                bool transition = false;

                if ((value_a < m_iso_value && value_b >= m_iso_value) || (value_a >= m_iso_value && value_b < m_iso_value)) {
                    transition = true;
                }

                // Calculating triangles if there is a transition

                if (transition)
                {
                    // Initializing vertices array and current edge

                    std::vector<int> edge_vertices;

                    int current_edge;

                    // Iterate over the 4 cells that share the edge

                    for (int i = 0; i < 4; i++)
                    {
                        int cell_x = x;
                        int cell_y = y;
                        int cell_z = z;

                        switch(i)
                        {
                            case 0:
                                current_edge = gris::EDGE_0;
                                break;
                            case 1:
                                cell_z -= 1;
                                current_edge = gris::EDGE_2;
                                break;
                            case 2:
                                cell_y -= 1;
                                cell_z -= 1;
                                current_edge = gris::EDGE_6;
                                break;
                            case 3:
                                cell_y -= 1;
                                current_edge = gris::EDGE_4;
                                break;
                            default:
                                assert(false);
                        }

                        // Checking if cell is within bounds

                        if (cell_x < 0 || cell_x >= m_volume_data.dimensions.x - 1 ||
                            cell_y < 0 || cell_y >= m_volume_data.dimensions.y - 1 ||
                            cell_z < 0 || cell_z >= m_volume_data.dimensions.z - 1)
                        {
                            continue;
                        }

                        // Finding whether current cell has dual point

                        int cell_index = cell_x + ((m_volume_data.dimensions.x - 1) * cell_y) + ((m_volume_data.dimensions.x - 1) * (m_volume_data.dimensions.y - 1) * cell_z);

                        CellDualPoints& current_cell = dual_points[cell_index];

                        for (int j = 0; j < current_cell.count; j++)
                        {
                            if (current_cell.patchMask[j] & current_edge)
                            {
                                edge_vertices.push_back(current_cell.vertexIndex[j]);
                            }
                        }
                    }

                    // Checking how many triangles to add
                    

                    if (edge_vertices.size() == 4)
                    {
                        int v0 = edge_vertices[0];
                        int v1 = edge_vertices[1];
                        int v2 = edge_vertices[2];
                        int v3 = edge_vertices[3];

                        glm::vec3 p0 = m_mesh.vertices[v0];
                        glm::vec3 p1 = m_mesh.vertices[v1];
                        glm::vec3 p2 = m_mesh.vertices[v2];
                        glm::vec3 p3 = m_mesh.vertices[v3];

                        glm::vec3 quadNormal = glm::cross(p1 - p0, p3 - p0);

                        glm::vec3 center = 0.25f * (p0 + p1 + p2 + p3);

                        if (glm::dot(quadNormal, center) < 0.0f)
                        {
                            std::swap(v1, v3);
                        }

                        m_mesh.triangles.push_back({v0, v1, v3});
                        m_mesh.triangles.push_back({v1, v2, v3});
                    }
                    else if (edge_vertices.size() == 3)
                    {
                        int v0 = edge_vertices[0];
                        int v1 = edge_vertices[1];
                        int v2 = edge_vertices[2];

                        glm::vec3 p0 = m_mesh.vertices[v0];
                        glm::vec3 p1 = m_mesh.vertices[v1];
                        glm::vec3 p2 = m_mesh.vertices[v2];

                        glm::vec3 triNormal = glm::cross(p1 - p0, p2 - p0);

                        glm::vec3 center = (p0 + p1 + p2) / 3.0f;

                        if (glm::dot(triNormal, center) < 0.0f)
                        {
                            std::swap(v1, v2);
                        }

                        m_mesh.triangles.push_back({v0, v1, v2});
                    }
                }
            }
        }
    }

    // Iterating over edges in y direction

    for (int x = 0; x < m_volume_data.dimensions.x; x++)
    {
        for (int y = 0; y < m_volume_data.dimensions.y - 1; y++)
        {
            for (int z = 0; z < m_volume_data.dimensions.z; z++)
            {
                // Checking if edge has transition of isovalue

                float value_a = m_volume_data.values[calculateIndex(glm::ivec3(x,y,z), m_volume_data.dimensions)];
                float value_b = m_volume_data.values[calculateIndex(glm::ivec3(x,y+1,z), m_volume_data.dimensions)];

                bool transition = false;

                if ((value_a < m_iso_value && value_b >= m_iso_value) || (value_a >= m_iso_value && value_b < m_iso_value)) {
                    transition = true;
                }

                // Calculating triangles if there is a transition

                if (transition)
                {
                    // Initializing vertices array and current edge

                    std::vector<int> edge_vertices;

                    int current_edge;

                    // Iterate over the 4 cells that share the edge

                    for (int i = 0; i < 4; i++)
                    {
                        int cell_x = x;
                        int cell_y = y;
                        int cell_z = z;

                        switch(i)
                        {
                            case 0:
                                current_edge = gris::EDGE_8;
                                break;
                            case 1:
                                cell_z -= 1;
                                current_edge = gris::EDGE_11;
                                break;
                            case 2:
                                cell_x -= 1;
                                cell_z -= 1;
                                current_edge = gris::EDGE_10;
                                break;
                            case 3:
                                cell_x -= 1;
                                current_edge = gris::EDGE_9;
                                break;
                            default:
                                assert(false);
                        }

                        // Checking if cell is within bounds

                        if (cell_x < 0 || cell_x >= m_volume_data.dimensions.x - 1 ||
                            cell_y < 0 || cell_y >= m_volume_data.dimensions.y - 1 ||
                            cell_z < 0 || cell_z >= m_volume_data.dimensions.z - 1)
                        {
                            continue;
                        }

                        // Finding whether current cell has dual point

                        int cell_index = cell_x + ((m_volume_data.dimensions.x - 1) * cell_y) + ((m_volume_data.dimensions.x - 1) * (m_volume_data.dimensions.y - 1) * cell_z);

                        CellDualPoints& current_cell = dual_points[cell_index];

                        for (int j = 0; j < current_cell.count; j++)
                        {
                            if (current_cell.patchMask[j] & current_edge)
                            {
                                edge_vertices.push_back(current_cell.vertexIndex[j]);
                            }
                        }
                    }

                    // Checking how many triangles to add

                    if (edge_vertices.size() == 4)
                    {
                        int v0 = edge_vertices[0];
                        int v1 = edge_vertices[1];
                        int v2 = edge_vertices[2];
                        int v3 = edge_vertices[3];

                        glm::vec3 p0 = m_mesh.vertices[v0];
                        glm::vec3 p1 = m_mesh.vertices[v1];
                        glm::vec3 p2 = m_mesh.vertices[v2];
                        glm::vec3 p3 = m_mesh.vertices[v3];

                        glm::vec3 quadNormal = glm::cross(p1 - p0, p3 - p0);

                        glm::vec3 center = 0.25f * (p0 + p1 + p2 + p3);

                        if (glm::dot(quadNormal, center) < 0.0f)
                        {
                            std::swap(v1, v3);
                        }

                        m_mesh.triangles.push_back({v0, v1, v3});
                        m_mesh.triangles.push_back({v1, v2, v3});
                    }
                    else if (edge_vertices.size() == 3)
                    {
                        int v0 = edge_vertices[0];
                        int v1 = edge_vertices[1];
                        int v2 = edge_vertices[2];

                        glm::vec3 p0 = m_mesh.vertices[v0];
                        glm::vec3 p1 = m_mesh.vertices[v1];
                        glm::vec3 p2 = m_mesh.vertices[v2];

                        glm::vec3 triNormal = glm::cross(p1 - p0, p2 - p0);

                        glm::vec3 center = (p0 + p1 + p2) / 3.0f;

                        if (glm::dot(triNormal, center) < 0.0f)
                        {
                            std::swap(v1, v2);
                        }

                        m_mesh.triangles.push_back({v0, v1, v2});
                    }
                }
            }
        }
    }

    // Iterating over edges in z direction

    for (int x = 0; x < m_volume_data.dimensions.x; x++)
    {
        for (int y = 0; y < m_volume_data.dimensions.y; y++)
        {
            for (int z = 0; z < m_volume_data.dimensions.z - 1; z++)
            {
                // Checking if edge has transition of isovalue

                float value_a = m_volume_data.values[calculateIndex(glm::ivec3(x,y,z), m_volume_data.dimensions)];
                float value_b = m_volume_data.values[calculateIndex(glm::ivec3(x,y,z+1), m_volume_data.dimensions)];

                bool transition = false;

                if ((value_a < m_iso_value && value_b >= m_iso_value) || (value_a >= m_iso_value && value_b < m_iso_value)) {
                    transition = true;
                }

                // Calculating triangles if there is a transition

                if (transition)
                {
                    // Initializing vertices array and current edge

                    std::vector<int> edge_vertices;

                    int current_edge;

                    // Iterate over the 4 cells that share the edge

                    for (int i = 0; i < 4; i++)
                    {
                        int cell_x = x;
                        int cell_y = y;
                        int cell_z = z;

                        switch(i)
                        {
                            case 0:
                                current_edge = gris::EDGE_3;
                                break;
                            case 1:
                                cell_x -= 1;
                                current_edge = gris::EDGE_1;
                                break;
                            case 2:
                                cell_x -= 1;
                                cell_y -= 1;
                                current_edge = gris::EDGE_5;
                                break;
                            case 3:
                                cell_y -= 1;
                                current_edge = gris::EDGE_7;
                                break;
                            default:
                                assert(false);
                        }

                        // Checking if cell is within bounds

                        if (cell_x < 0 || cell_x >= m_volume_data.dimensions.x - 1 ||
                            cell_y < 0 || cell_y >= m_volume_data.dimensions.y - 1 ||
                            cell_z < 0 || cell_z >= m_volume_data.dimensions.z - 1)
                        {
                            continue;
                        }

                        // Finding whether current cell has dual point

                        int cell_index = cell_x + ((m_volume_data.dimensions.x - 1) * cell_y) + ((m_volume_data.dimensions.x - 1) * (m_volume_data.dimensions.y - 1) * cell_z);

                        CellDualPoints& current_cell = dual_points[cell_index];

                        for (int j = 0; j < current_cell.count; j++)
                        {
                            if (current_cell.patchMask[j] & current_edge)
                            {
                                edge_vertices.push_back(current_cell.vertexIndex[j]);
                            }
                        }
                    }

                    // Checking how many triangles to add

                    if (edge_vertices.size() == 4)
                    {
                        int v0 = edge_vertices[0];
                        int v1 = edge_vertices[1];
                        int v2 = edge_vertices[2];
                        int v3 = edge_vertices[3];

                        glm::vec3 p0 = m_mesh.vertices[v0];
                        glm::vec3 p1 = m_mesh.vertices[v1];
                        glm::vec3 p2 = m_mesh.vertices[v2];
                        glm::vec3 p3 = m_mesh.vertices[v3];

                        glm::vec3 quadNormal = glm::cross(p1 - p0, p3 - p0);

                        glm::vec3 center = 0.25f * (p0 + p1 + p2 + p3);

                        if (glm::dot(quadNormal, center) < 0.0f)
                        {
                            std::swap(v1, v3);
                        }

                        m_mesh.triangles.push_back({v0, v1, v3});
                        m_mesh.triangles.push_back({v1, v2, v3});
                    }
                    else if (edge_vertices.size() == 3)
                    {
                        int v0 = edge_vertices[0];
                        int v1 = edge_vertices[1];
                        int v2 = edge_vertices[2];

                        glm::vec3 p0 = m_mesh.vertices[v0];
                        glm::vec3 p1 = m_mesh.vertices[v1];
                        glm::vec3 p2 = m_mesh.vertices[v2];

                        glm::vec3 triNormal = glm::cross(p1 - p0, p2 - p0);

                        glm::vec3 center = (p0 + p1 + p2) / 3.0f;

                        if (glm::dot(triNormal, center) < 0.0f)
                        {
                            std::swap(v1, v2);
                        }

                        m_mesh.triangles.push_back({v0, v1, v2});
                    }
                }
            }
        }
    }

    // Calculating normals based on the dataset

    if (m_is_trivariate) {
        // Using analytic gradient

        // Initializing golden ratio constant
    
        double tau = 0.5*(1.0+ sqrt(5.0));
        double tau_2 = pow(tau, 2.0);

        // Calculating half of the dimensions for normalization

        double half_x = static_cast<double>(m_volume_data.dimensions.x) * 0.5;
        double half_y = static_cast<double>(m_volume_data.dimensions.y) * 0.5;
        double half_z = static_cast<double>(m_volume_data.dimensions.z) * 0.5;

        // Implementing a scaling factor for better visualization afer normalization
        
        float scale_factor = 8.0f /std::max(m_volume_data.dimensions.x, std::max(m_volume_data.dimensions.y, m_volume_data.dimensions.z));
        
        // Iterating over vertices

        for (int i = 0; i < m_mesh.vertices.size(); i++)
        {
            // Converting current vertex in world space back to volume data space
            glm::vec3 transformed_vertex = ((m_mesh.vertices[i] - m_bounding_box.min)/(m_bounding_box.max - m_bounding_box.min)) * glm::vec3(m_volume_data.dimensions - glm::ivec3(1.0,1.0,1.0));

            // Extracting x, y, z coordinates
            double x = static_cast<double>(transformed_vertex.x);
            double y = static_cast<double>(transformed_vertex.y);
            double z = static_cast<double>(transformed_vertex.z);


            // Modifying current x, y, z to account for negative coordinates
            x -= half_x;
            y -= half_y;
            z -= half_z;

            // Applying scaling factor
            x *= scale_factor;
            y *= scale_factor;
            z *= scale_factor;

            // Calculating powers for each coordinate
            double x_2 = x*x;
            double y_2 = y*y;
            double z_2 = z*z;
            double r = (x_2 + y_2 + z_2 - 1.0);

            // Calculating partial derivatives for each coordinate based on Barth's sextic formula

            double partial_x = 8*tau_2*x*(tau_2*z_2 - x_2)*(tau_2*y_2 - z_2) - 8*x*(tau_2*x_2 - y_2)*(tau_2*y_2 - z_2) - 4*(1.0 + 2.0*tau)*x*r;
            double partial_y = 8*tau_2*y*(tau_2*x_2 - y_2)*(tau_2*z_2 - x_2) - 8*y*(tau_2*y_2 - z_2)*(tau_2*z_2 - x_2) - 4*(1.0 + 2.0*tau)*y*r;
            double partial_z = 8*tau_2*z*(tau_2*y_2 - z_2)*(tau_2*x_2 - y_2) - 8*z*(tau_2*z_2 - x_2)*(tau_2*x_2 - y_2) - 4*(1.0 + 2.0*tau)*z*r;

            // Storing normal in mesh normals
            m_mesh.normals.push_back(glm::normalize(-glm::vec3(partial_x, partial_y, partial_z)));
        }
    }
    else {
        // Using central finite differences

        // Iterating over vertices

        for (int i = 0; i < m_mesh.vertices.size(); i++)
        {
            // Converting current coordinate back to grid space
            glm::vec3 transformed_vertex = ((m_mesh.vertices[i] - m_bounding_box.min)/(m_bounding_box.max - m_bounding_box.min)) * glm::vec3(m_volume_data.dimensions - glm::ivec3(1.0,1.0,1.0));

            // Extracting x, y, z coordinates and converting to integers for indexing
            int x = static_cast<int>(transformed_vertex.x);
            int y = static_cast<int>(transformed_vertex.y);
            int z = static_cast<int>(transformed_vertex.z);

            // Clamping coordinates to be within the grid space
            x = std::max(1, std::min(x, m_volume_data.dimensions.x - 2));
            y = std::max(1, std::min(y, m_volume_data.dimensions.y - 2));
            z = std::max(1, std::min(z, m_volume_data.dimensions.z - 2));

            // Calculating indices

            int x_plus_1 = calculateIndex(glm::ivec3(x+1,y,z), m_volume_data.dimensions);
            int x_minus_1 = calculateIndex(glm::ivec3(x-1,y,z), m_volume_data.dimensions);
            int y_plus_1 = calculateIndex(glm::ivec3(x,y+1,z), m_volume_data.dimensions);
            int y_minus_1 = calculateIndex(glm::ivec3(x,y-1,z), m_volume_data.dimensions);
            int z_plus_1 = calculateIndex(glm::ivec3(x,y,z+1), m_volume_data.dimensions);
            int z_minus_1 = calculateIndex(glm::ivec3(x,y,z-1), m_volume_data.dimensions);

            // Calculating central finite differences for each coordinate
            double partial_x = ((m_volume_data.values[x_plus_1]) - (m_volume_data.values[x_minus_1])) / (2.0f * size_of_cell.x);
            double partial_y = ((m_volume_data.values[y_plus_1]) - (m_volume_data.values[y_minus_1])) / (2.0f * size_of_cell.y);
            double partial_z = ((m_volume_data.values[z_plus_1]) - (m_volume_data.values[z_minus_1])) / (2.0f * size_of_cell.z);

            // Storing normal in mesh normals
            m_mesh.normals.push_back(glm::normalize(-glm::vec3(partial_x, partial_y, partial_z)));
        }
    }
}

void VolumeVisualisation::snapToGrid(float distance) {
    // TODO(4.5):
}

void cleanUpTriangleSoup() {
    // TODO(4.5):
}

glm::vec3 VolumeVisualisation::computeEdgeIntersection(int x, int y, int z, int edge)
{
    glm::ivec3 p0;
    glm::ivec3 p1;

    glm::vec3 voxel_size = (m_bounding_box.max - m_bounding_box.min) / glm::vec3(m_volume_data.dimensions.x - 1, m_volume_data.dimensions.y - 1, m_volume_data.dimensions.z - 1);

    switch(edge)
    {
        case 0:
            p0 = {x, y, z};
            p1 = {x+1, y, z};
            break;
        case 1:
            p0 = {x+1, y, z};
            p1 = {x+1, y, z+1};
            break;
        case 2:
            p0 = {x, y, z+1};
            p1 = {x+1, y, z+1};
            break;
        case 3:
            p0 = {x, y, z};
            p1 = {x, y, z+1};
            break;
        case 4:
            p0 = {x, y+1, z};
            p1 = {x+1, y+1, z};
            break;
        case 5:
            p0 = {x+1, y+1, z};
            p1 = {x+1, y+1, z+1};
            break;
        case 6:
            p0 = {x, y+1, z+1};
            p1 = {x+1, y+1, z+1};
            break;
        case 7:
            p0 = {x, y+1, z};
            p1 = {x, y+1, z+1};
            break;
        case 8:
            p0 = {x, y, z};
            p1 = {x, y+1, z};
            break;
        case 9:
            p0 = {x+1, y, z};
            p1 = {x+1, y+1, z};
            break;
        case 10:
            p0 = {x+1, y, z+1};
            p1 = {x+1, y+1, z+1};
            break;
        case 11:
            p0 = {x, y, z+1};
            p1 = {x, y+1, z+1};
            break;
        default:
            assert(false);
            return glm::vec3(0.0f);
    }

    float v0 = m_volume_data.values[calculateIndex(p0, m_volume_data.dimensions)];
    float v1 = m_volume_data.values[calculateIndex(p1, m_volume_data.dimensions)];

    if (std::abs(v1 - v0) < 1e-6f)
    {
        return 0.5f * (glm::vec3(p0) + glm::vec3(p1));
    }
    else
    {
        float t = (m_iso_value - v0) / (v1 - v0);

        glm::vec3 pos0 = m_bounding_box.min + voxel_size * glm::vec3(p0);
        glm::vec3 pos1 = m_bounding_box.min + voxel_size * glm::vec3(p1);

        return pos0 + t * (pos1 - pos0);
    }
}