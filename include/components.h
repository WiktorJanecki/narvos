#pragma once

#include "transformComponent.h"
#include "textureComponent.h"
#include "rectComponent.h"
#include "physicsComponent.h"


typedef struct{
    TransformComponent_t* transformComponent;
    TextureComponent_t* textureComponent;
    RectComponent_t* rectComponent;
    PhysicsComponent_t* physicsComponent;
} Components_t;

