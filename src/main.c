#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "entity.h"
#include "transformComponent.h"
#include "systems.h"

int main(){
    if(SDL_Init(SDL_INIT_EVERYTHING)){
        printf("Failed to init sdl");
        return 0;
    }

    SDL_Window *window = SDL_CreateWindow("narvos",0,0,1280,720,0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    SDL_Event event;
    
    unsigned int lastTime = 0, currentTime, fps = 0;

    Entity_t entity;
    TransformComponent_t transformComponent;
    transformComponent.x = 64;
    transformComponent.y = 96;
    entity.components.transformComponent = &transformComponent;
    
    setSystemsRenderer(renderer);

    while(1){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                SDL_Quit();
                return 0;
            }
        }

        fps++;
        currentTime = SDL_GetTicks();
        if(currentTime > lastTime + 1000){
            printf("FPS :%d\n",fps);
            fps = 0;
            lastTime = currentTime;
        }
    
        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        SDL_RenderClear(renderer);
        updateSystems(entity);
        SDL_RenderPresent(renderer);
    }
}
