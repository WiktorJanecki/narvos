#include "systems.h"

void setSystemsRenderer(SDL_Renderer* renderer){
    g_renderer = renderer;
}

void updateSystems(Entity_t ent){
    updateRenderingSystem(ent);
}
