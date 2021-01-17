#pragma once

#include "components.h"


enum {
    ENT_IS_PLAYER = 1 << 0,
    ENT_IS_COLLIDING = 1 << 2,
};

typedef struct{
    Components_t components;
    int flags;
} Entity_t;
