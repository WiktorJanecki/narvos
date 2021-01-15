#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "entity.h"
#include "transformComponent.h"
#include "systems.h"

int main(){
    SDL_Window *window = SDL_CreateWindow("narvos",0,0,1280,720,0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    SDL_Event event;

    while(1){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                SDL_Quit();
                return 0;
            }
        }
    }





}
