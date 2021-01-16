#define VERSION "0y2v0"
#define DEBUG 1


#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "entity.h"
#include "systems.h"
#include "log.h"

int main(){
    if(SDL_Init(SDL_INIT_EVERYTHING)){
        SYS_err("Failed to init SDL2!\n");
        return 0;
    }

    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    if ((IMG_Init(flags) & flags) != flags) {
        SYS_err("Failed to init SDL2_image!\n");
        SYS_err("IMG_Init: %s\n", IMG_GetError());
    }

    SDL_Window *window = SDL_CreateWindow("narvos",0,0,1280,720,0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
    SDL_Event event;
    
    SYS_log("\n Narvos has started \n ");                  //log starting game info
    if(DEBUG){SYS_warn("Game started in debug mode\n ");}
    SYS_log("Version: %s\n\n",VERSION);

    unsigned int dtLastTime = 0, fpsLastTime = 0, currentTime, fps = 0;
    bool keys[322];
    float dt = 0;

    Entity_t entity;
    TransformComponent_t transformComponent;
    transformComponent.position.x = 64;
    transformComponent.position.y = 64;
    entity.components.transformComponent = &transformComponent;
    TextureComponent_t textureComponent;
    textureComponent.path = "res/textures/txt.png";
    entity.components.textureComponent = &textureComponent;
    RectComponent_t rectComponent;
    rectComponent.width = 512;
    rectComponent.height = 512;
    entity.components.rectComponent = &rectComponent;
    PhysicsComponent_t physicsComponent;
    physicsComponent.velocity.x = 500;
    physicsComponent.friction = 250;
    entity.components.physicsComponent = &physicsComponent;
    
    SYS_SetSystemsRenderer(renderer);
    SYS_SetDeltaTime(&dt);
    SYS_StartSystems(&entity);

    while(1){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                SDL_Quit();
                return 0;
            }
            else if(event.type == SDL_KEYDOWN){
                keys[event.key.keysym.sym] = true;    
                SYS_SetKeyboardState(keys);
            }
            else if(event.type == SDL_KEYUP){
                keys[event.key.keysym.sym] = false;
                SYS_SetKeyboardState(keys);
            }
        }

        fps++;
        currentTime = SDL_GetTicks();
        if(currentTime > fpsLastTime + 1000){ //do every second
            char buf[25];
            snprintf(buf,25,"narvos    FPS: %d",fps); //append fps count to string
            SDL_SetWindowTitle(window,buf);

            fps = 0;
            fpsLastTime = currentTime;
        }
        dt = (currentTime - dtLastTime)/1000.f;
        dtLastTime = currentTime;

        SYS_UpdateSystems(&entity);
    
        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        SDL_RenderClear(renderer);
        SYS_RenderSystems(&entity);
        SDL_RenderPresent(renderer);
    }
    SYS_Free();
}
