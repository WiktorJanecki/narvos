#define VERSION "0y3v0"
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
    bool keys[322]; //uninitialized will be randomly wtf..just initialize
    for(int i = 0; i < 322;i++){
        keys[i] = false;
    }
    float dt = 0;

    unsigned int entities_length = 3;
    Entity_t* entities = (Entity_t*)malloc(entities_length*sizeof(Entity_t));
    Entity_t entity;
    TransformComponent_t transformComponent;
    transformComponent.position.x = 0;
    transformComponent.position.y = 0;
    entity.components.transformComponent = &transformComponent;
    TextureComponent_t textureComponent;
    textureComponent.path = "res/textures/txt.png";
    entity.components.textureComponent = &textureComponent;
    RectComponent_t rectComponent;
    rectComponent.width = 64;
    rectComponent.height = 64;
    entity.components.rectComponent = &rectComponent;
    PhysicsComponent_t physicsComponent;
    physicsComponent.acceleration.x = 0; //if uninitialized are like -532847e10
    physicsComponent.acceleration.y = 0;
    physicsComponent.velocity.x = 0;
    physicsComponent.velocity.y = 0;
    entity.components.physicsComponent = &physicsComponent;
    entity.flags = ENT_IS_PLAYER;
    entities[0] = entity;

    Entity_t wall;
    TransformComponent_t transformComponent2;
    transformComponent2.position.x = 640;
    transformComponent2.position.y = 256;
    wall.components.transformComponent = &transformComponent2;
    TextureComponent_t textureComponent2;
    textureComponent2.path = "res/textures/txt.png";
    wall.components.textureComponent = &textureComponent2;
    RectComponent_t rectComponent2;
    rectComponent2.width = 256;
    rectComponent2.height = 256;
    wall.components.rectComponent = &rectComponent2;
    PhysicsComponent_t physicsComponent2;
    physicsComponent2.acceleration.x = 0;
    physicsComponent2.acceleration.y = 0;
    physicsComponent2.velocity.x = 0;
    physicsComponent2.velocity.y = 0;
    wall.components.physicsComponent = &physicsComponent2;
    entities[1] = wall;

    Entity_t wall1;
    TransformComponent_t transformComponent3;
    transformComponent3.position.x = 128;
    transformComponent3.position.y = 64;
    wall1.components.transformComponent = &transformComponent3;
    TextureComponent_t textureComponent3;
    textureComponent3.path = "res/textures/txt.png";
    wall1.components.textureComponent = &textureComponent3;
    RectComponent_t rectComponent3;
    rectComponent3.width = 512;
    rectComponent3.height = 512;
    wall1.components.rectComponent = &rectComponent3;
    PhysicsComponent_t physicsComponent3;
    physicsComponent3.acceleration.x = 0;
    physicsComponent3.acceleration.y = 0;
    physicsComponent3.velocity.x = 0;
    physicsComponent3.velocity.y = 0;
    wall1.components.physicsComponent = &physicsComponent3;
    entities[2] = wall1;

    SYS_SetSystemsRenderer(renderer);
    SYS_SetDeltaTime(&dt);
    SYS_SetEntities(entities,entities_length);
    for(unsigned int i = 0; i < entities_length; i++){
        SYS_StartSystems(&entities[i]);
    }

    while(1){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                SDL_Quit();
                return 0;
            }
            else if(event.type == SDL_KEYDOWN && event.key.keysym.sym < 322){ //some keys like caps lock are overfloting our keybuffer
                keys[event.key.keysym.sym] = true;    
                SYS_SetKeyboardState(keys);
            }
            else if(event.type == SDL_KEYUP && event.key.keysym.sym < 322){
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

        for(unsigned int i = 0; i < entities_length; i++){
            SYS_UpdateSystems(&entities[i]);
        }
    
        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        SDL_RenderClear(renderer);
        for(unsigned int i = 0; i < entities_length; i++){
            SYS_RenderSystems(&entities[i]);
        }
        SDL_RenderPresent(renderer);
    }
    SYS_Free();
    free(entities);
}
