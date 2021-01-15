#include "renderingSystem.h"

#include <SDL2/SDL_image.h>

SDL_Renderer* g_renderer;

void startRenderingSystem(Entity_t ent){
    if(ent.components.textureComponent){
        if(ent.components.textureComponent->path){
            ent.components.textureComponent->texture = IMG_LoadTexture(g_renderer,ent.components.textureComponent->path);
        }
    }
}

void renderRenderingSystem(Entity_t ent){
    if(ent.components.textureComponent->texture&&ent.components.transformComponent){
        SDL_Rect rect;
        rect.x = ent.components.transformComponent->x;
        rect.y = ent.components.transformComponent->y;
        rect.w = 64;
        rect.h = 64;
        SDL_RenderCopy(g_renderer,ent.components.textureComponent->texture,NULL,&rect);
    }
}

void updateRenderingSystem(Entity_t ent){}
