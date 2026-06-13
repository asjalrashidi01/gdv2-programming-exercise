#pragma once

struct GirdCell {
    bool corners;
};

// Given a grid cell and an isolevel, calculate the triangular
//  facets required to represent the isosurface through the cell.
// Return the number of triangular facets, the array "triangles"
//  will be loaded up with the vertices at most 5 triangular facets.
//  0 will be returned if the grid cell is either totally above
//  of totally below the isolevel.
unsigned int polygonize(GRIDCELL grid, float isolevel, MC_TRIANGLE* triangles);

// Linearly interpolate the position where an isosurface cuts an
//  edge between two vertices, each with their own scalar value
glm::vec3 vertexInterp(float isolevel, glm::vec3 p1, glm::vec3 p2, float valp1, float valp2)
