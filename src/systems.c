#include "systems.h"

float* g_dt;
bool g_keyboardState[322];
unsigned int g_entities_length;
Entity_t* g_entities; //array

void SYS_SetSystemsRenderer(SDL_Renderer* renderer){
    g_renderer = renderer;
}

void SYS_SetDeltaTime(float* dt){
    g_dt = dt;
}

void SYS_SetKeyboardState(bool state[322]){
    for(int i = 0; i < 322; i++){
        g_keyboardState[i] = state[i];
    }
}

void SYS_SetEntities(Entity_t* entities, unsigned int entities_length){
    g_entities_length = entities_length;
    g_entities = entities;
}

void SYS_StartSystems(Entity_t* ent){
    startRenderingSystem(ent);
    startPhysicsSystem(ent);
}

void SYS_UpdateSystems(Entity_t* ent){
    updateRenderingSystem(ent);
    updatePhysicsSystem(ent);
    updateMovementSystem(ent);
}

void SYS_RenderSystems(Entity_t* ent){
    renderRenderingSystem(ent);
    renderPhysicsSystem(ent);
}
void SYS_Free(){}
