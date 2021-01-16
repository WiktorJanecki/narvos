#pragma once

#include "renderingSystem.h"
#include "physicsSystem.h"
#include "movementSystem.h"
#include "entity.h"
#include <SDL2/SDL.h>
#include <stdbool.h>


extern SDL_Renderer* g_renderer;
extern float* g_dt;
extern bool g_keyboardState[322];

void SYS_SetSystemsRenderer(SDL_Renderer*);
void SYS_SetDeltaTime(float*);

void SYS_SetKeyboardState(bool[322]);

void SYS_StartSystems(Entity_t*);
void SYS_UpdateSystems(Entity_t*);
void SYS_RenderSystems(Entity_t*);

void SYS_Free();
