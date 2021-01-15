#pragma once

#include "transformComponent.h"
#include "textureComponent.h"
#include "rectComponent.h"


typedef struct{
    TransformComponent_t* transformComponent;
    TextureComponent_t* textureComponent;
    RectComponent_t* rectComponent;
} Components_t;

