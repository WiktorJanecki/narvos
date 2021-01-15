#pragma once

#include "renderingSystem.h"
#include "entity.h"
#include <SDL2/SDL.h>

extern SDL_Renderer* g_renderer;

void setSystemsRenderer(SDL_Renderer*);
void updateSystems(Entity_t);
