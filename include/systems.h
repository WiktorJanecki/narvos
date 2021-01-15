#pragma once

#include "renderingSystem.h"
#include "entity.h"
#include <SDL2/SDL.h>

extern SDL_Renderer* g_renderer;

void SYS_SetSystemsRenderer(SDL_Renderer*);
void SYS_UpdateSystems(Entity_t);
void SYS_RenderSystems(Entity_t);
void SYS_Free();
