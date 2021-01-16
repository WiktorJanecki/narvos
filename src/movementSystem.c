#include "movementSystem.h"
#include "mathematica.h"

#define MOVEMENT_SPEED 250
#define MOVEMENT_FRICTION 1000

Vector2f_t g_LastMovementForce;

void updateMovementSystem(Entity_t *ent){
    if(ent->components.physicsComponent){
        ent->components.physicsComponent->friction = 0;
        ent->components.physicsComponent->velocity.x -= g_LastMovementForce.x;
        ent->components.physicsComponent->velocity.y -= g_LastMovementForce.y;
        Vector2f_t* vel = &ent->components.physicsComponent->velocity;
        float dt = *g_dt;
        float fri = MOVEMENT_FRICTION;
        Vector2f_t movementForce;
        if(g_keyboardState[SDLK_w]){
            movementForce.y = -MOVEMENT_SPEED;
        }
        if(g_keyboardState[SDLK_s]){
            movementForce.y = MOVEMENT_SPEED;
        }
        if(g_keyboardState[SDLK_a]){
            movementForce.x = -MOVEMENT_SPEED;
        }
        if(g_keyboardState[SDLK_d]){
            movementForce.x = MOVEMENT_SPEED;
        }
        ent->components.physicsComponent->velocity.x += movementForce.x;
        ent->components.physicsComponent->velocity.y += movementForce.y;
        if(vel->x > 0){
            vel->x += -fri * dt;
        }
        if(vel->x < 0){
            vel->x += fri * dt;
        }
        if(vel->y > 0){
            vel->y += -fri * dt;
        }
        if(vel->y < 0){
            vel->y += fri * dt;
        }
        g_LastMovementForce.x = movementForce.x;
        g_LastMovementForce.y = movementForce.y;
        if(g_LastMovementForce.x > 0){
            g_LastMovementForce.x += -fri * dt;
        }
        if(g_LastMovementForce.x < 0){
            g_LastMovementForce.x += fri * dt;
        }
        if(g_LastMovementForce.y > 0){
            g_LastMovementForce.y += -fri * dt;
        }
        if(g_LastMovementForce.y < 0){
            g_LastMovementForce.y += fri * dt;
        }

    }
}
