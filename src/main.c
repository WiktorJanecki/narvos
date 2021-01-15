#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "entity.h"
#include "transformComponent.h"
#include "systems.h"

int main(){
    if(SDL_Init(SDL_INIT_EVERYTHING)){
        printf("Failed to init SDL2!");
        return 0;
    }

    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    if ((IMG_Init(flags) & flags) != flags) {
        printf("Failed to init SDL2_image!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
    }

    SDL_Window *window = SDL_CreateWindow("narvos",0,0,1280,720,0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
    SDL_Event event;
    
    unsigned int lastTime = 0, currentTime, fps = 0;

    Entity_t entity;
    TransformComponent_t transformComponent;
    transformComponent.x = 64;
    transformComponent.y = 96;
    entity.components.transformComponent = &transformComponent;
    TextureComponent_t textureComponent;
    textureComponent.path = "res/textures/txt.png";
    entity.components.textureComponent = &textureComponent;
    
    SYS_SetSystemsRenderer(renderer);
    SYS_StartSystems(entity);

    while(1){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                SDL_Quit();
                return 0;
            }
        }

        fps++;
        currentTime = SDL_GetTicks();
        if(currentTime > lastTime + 1000){ //do every second
            char buf[25];
            snprintf(buf,25,"narvos    FPS: %d",fps); //append fps count to string
            SDL_SetWindowTitle(window,buf);

            fps = 0;
            lastTime = currentTime;
        }
        SYS_UpdateSystems(entity);
    
        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        SDL_RenderClear(renderer);
        SYS_RenderSystems(entity);
        SDL_RenderPresent(renderer);
    }
    SYS_Free();
}
