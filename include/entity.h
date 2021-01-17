#pragma once

#include "components.h"


enum {
    ENT_IS_PLAYER = 1 << 0,
    ENT_IS_COLLIDING = 1 << 2,
};

typedef struct{
    Components_t components;
    int flags;
    char* category;
} Entity_t;

Entity_t* ENT_CreateWall(float x, float y,float width, float height, char* texturePath);
void ENT_FreeEntity(Entity_t*);
