#pragma once
#include <QOpenGLFunctions_2_1>
#include <glm/glm.hpp>
#include <vector>

namespace gris {
struct TriangleMesh {
    std::vector<glm::fvec3> vertices;
    std::vector<glm::fvec3> normals;
    std::vector<glm::ivec3> triangles;
};
} // namespace gris
