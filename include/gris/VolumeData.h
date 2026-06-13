#pragma once

#include <QOpenGLFunctions_2_1>
#include <glm/glm.hpp>
#include <gris/BoundingBox.h>
#include <vector>

namespace gris {
struct VolumeData {
    std::vector<float> values;
    glm::ivec3 dimensions = {0, 0, 0};
};
} // namespace gris
