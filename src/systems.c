#include "systems.h"

void SYS_SetSystemsRenderer(SDL_Renderer* renderer){
    g_renderer = renderer;
}

void SYS_UpdateSystems(Entity_t ent){
    updateRenderingSystem(ent);
}

void SYS_RenderSystems(Entity_t ent){
    renderRenderingSystem(ent);
}
void SYS_Free(){}
