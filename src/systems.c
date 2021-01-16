#include "systems.h"

float* g_dt;

void SYS_SetSystemsRenderer(SDL_Renderer* renderer){
    g_renderer = renderer;
}

void SYS_SetDeltaTime(float* dt){
    g_dt = dt;
}

void SYS_StartSystems(Entity_t* ent){
    startRenderingSystem(ent);
    startPhysicsSystem(ent);
}

void SYS_UpdateSystems(Entity_t* ent){
    updateRenderingSystem(ent);
    updatePhysicsSystem(ent);
}

void SYS_RenderSystems(Entity_t* ent){
    renderRenderingSystem(ent);
    renderPhysicsSystem(ent);
}
void SYS_Free(){}
