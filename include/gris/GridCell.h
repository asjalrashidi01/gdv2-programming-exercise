#pragma once

#include "gris/BoundingBox.h"

namespace gris {
struct GridCell {
    float values[8];
    gris::BoundingBox volume;
};
} // namespace gris
