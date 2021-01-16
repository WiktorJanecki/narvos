#include "physicsSystem.h"

#include "mathematica.h"
#include "log.h"


void startPhysicsSystem(Entity_t *ent){}

void updatePhysicsSystem(Entity_t* ent){
    if(ent->components.physicsComponent && ent->components.transformComponent){
        Vector2f_t acc = ent->components.physicsComponent->acceleration;
        float fri = ent->components.physicsComponent->friction;
        float dt = *g_dt;
        ent->components.physicsComponent->velocity.x += acc.x * dt;
        ent->components.physicsComponent->velocity.y += acc.y * dt;
        Vector2f_t vel = ent->components.physicsComponent->velocity;
        if(vel.x > 0){
            ent->components.physicsComponent->velocity.x += -fri * dt;
        }
        if(vel.x < 0){
            ent->components.physicsComponent->velocity.x += fri * dt;
        }
        if(vel.y > 0){
            ent->components.physicsComponent->velocity.y += -fri * dt;
        }
        if(vel.y < 0){
            ent->components.physicsComponent->velocity.y += fri * dt;
        }

        vel = ent->components.physicsComponent->velocity;
        ent->components.transformComponent->position.x += vel.x*dt;
        ent->components.transformComponent->position.y += vel.y*dt;
    }
}

void renderPhysicsSystem(Entity_t* ent){}
