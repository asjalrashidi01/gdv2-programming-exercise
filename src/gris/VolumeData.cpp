#include "gris/VolumeData.h"

#include "gris/TriangeMesh.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <fstream>
#include <glm/ext.hpp>
#include <glm/gtx/extend.hpp>
#include <iostream>
#include <vector>

gris::VolumeData gris::loadVolumeData(glm::ivec3 dimensions, const std::string& path) {
    std::ifstream in(path, std::ios_base::in | std::ios_base::binary);

    gris::VolumeData volume_data = {
        .values = std::vector<float>(dimensions.x * dimensions.y * dimensions.z),
        .dimensions = dimensions
    };

    // we know the bit depth (8 bits by now), so all that's left is to cast each char to a float between [0,1)
    for(int i = 0; i < dimensions.x * dimensions.y * dimensions.z; ++i) {
        float v = static_cast<unsigned char>(in.get()) / 256.0f;
        volume_data.values[i] = v;
    }
    return volume_data;
}
