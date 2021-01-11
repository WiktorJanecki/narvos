#pragma once

#include "components/component.h"
#include "math/vector.h"

struct TransformComponent : Component{

    Vector2f position = Vector2f(0,0);
    Vector2f scale = Vector2f(0,0);
    float rotation = 0.f;

        
};