#pragma once

#include "mathematica.h"

typedef struct{
    Vector2f_t velocity;
    Vector2f_t acceleration;
    float friction;
} PhysicsComponent_t;
