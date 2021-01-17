#pragma once

#include "components.h"


enum {
    ENT_IS_PLAYER = 1 << 0,
};

typedef struct{
    Components_t components;
    unsigned int flags;
} Entity_t;
