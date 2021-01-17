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
        if(ent->flags & ENT_IS_PLAYER && ent->components.rectComponent){ //if player dont let him collide
            bool collisionOnX = false;
            bool collisionOnY = false;
            
            float nx = vel.x*dt;
            float ny = vel.y*dt;

            float incrX = nx + ent->components.transformComponent->position.x;
            float incrY = ny + ent->components.transformComponent->position.y;
            float x = ent->components.transformComponent->position.x;
            float y = ent->components.transformComponent->position.y;
            float w = ent->components.rectComponent->width;
            float h = ent->components.rectComponent->height;

            for(unsigned int i = 0; i < g_entities_length;i++){
                Entity_t* col = &g_entities[i];
                if(col->components.rectComponent&&col->components.transformComponent&&!(col->flags & ENT_IS_PLAYER)){
                    float colX = col->components.transformComponent->position.x;
                    float colY = col->components.transformComponent->position.y;
                    float colW = col->components.rectComponent->width;
                    float colH = col->components.rectComponent->height;

                        if( incrX < colX + colW &&
                            incrX + w > colX &&
                            y < colY + colH &&
                            y + h > colY){
                                collisionOnX = true;
                        }
                        if( x < colX + colW && //TODO
                            x + w > colX &&
                            incrY < colY + colH &&
                            incrY + h > colY){
                                collisionOnY = true;
                        }
                }
            }
            if(!collisionOnX){
                ent->components.transformComponent->position.x += vel.x * dt;
            }
            if(!collisionOnY){
                ent->components.transformComponent->position.y += vel.y * dt;
            }
        }
        else{
            ent->components.transformComponent->position.x += vel.x*dt;
            ent->components.transformComponent->position.y += vel.y*dt;
        }
    }
}

void renderPhysicsSystem(Entity_t* ent){}
