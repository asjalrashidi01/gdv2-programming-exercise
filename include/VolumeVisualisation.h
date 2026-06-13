#pragma once

#include "gris/GridCell.h"
#include "gris/TriangeMesh.h"
#include "gris/VolumeData.h"

class VolumeVisualisation {
public:
    explicit VolumeVisualisation(const gris::BoundingBox& bounding_box);

    void generateTriviateVolumeData(const glm::ivec3& dimensions, const gris::BoundingBox& bounding_box);
    void loadRawVolumeData(const std::string& path, const glm::ivec3& dimensions, const gris::BoundingBox& bounding_box);

    void generateMesh(float iso_value, bool dual, bool grid_snapping, float grid_snapping_distance, bool optimize_mesh);

    void drawMesh(QOpenGLFunctions_2_1* f) const;
    void drawNormals(QOpenGLFunctions_2_1* f) const;
    void drawVolumeData(QOpenGLFunctions_2_1* f) const;
    void drawBoundingBox(QOpenGLFunctions_2_1* f) const;

private:
    static gris::TriangleMesh poligonize(const gris::GridCell& grid_cell, float iso_value);

    void marchingCubes();
    void dualMarchingCubes();

    void snapToGrid(float distance);
    void cleanUpTriangleSoup();

    gris::BoundingBox m_bounding_box;
    bool m_is_trivariate;
    float m_iso_value;
    gris::VolumeData m_volume_data;
    gris::TriangleMesh m_mesh;
};
