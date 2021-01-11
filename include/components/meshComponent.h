#pragma once

#include <vector>

#include "components/component.h"

struct MeshComponent : Component{

    std::vector<float> positions = {};
    std::vector<float> textures = {};
    std::vector<int> indices = {};

    int vaoID = 0;
};