#include "renderingSystem.h"

SDL_Renderer* g_renderer;

void renderRenderingSystem(Entity_t ent){
    if(ent.components.transformComponent){
        SDL_Rect rect;
        rect.x = ent.components.transformComponent->x;
        rect.y = ent.components.transformComponent->y;
        rect.w = 64;
        rect.h = 64;
        SDL_SetRenderDrawColor(g_renderer,255,255,255,255);
        SDL_RenderDrawRect(g_renderer,&rect);
    }
}

void updateRenderingSystem(Entity_t ent){}
