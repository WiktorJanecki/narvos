#include "entity.h"


Entity_t* ENT_CreateWall(float x, float y,float width, float height, char* texturePath){
    Entity_t* entity = (Entity_t*) malloc(sizeof(Entity_t)); 


    TransformComponent_t* transformComponent = (TransformComponent_t*) malloc(sizeof(TransformComponent_t));
    transformComponent->position.x = x;
    transformComponent->position.y = y;
    entity->components.transformComponent = transformComponent;
    TextureComponent_t* textureComponent = (TextureComponent_t*) malloc(sizeof(TextureComponent_t));
    textureComponent->path = texturePath;
    entity->components.textureComponent = textureComponent;
    RectComponent_t* rectComponent = (RectComponent_t*) malloc(sizeof(RectComponent_t));
    rectComponent->width = width;
    rectComponent->height = height;
    rectComponent->x = 0;
    rectComponent->y = 0;
    entity->components.rectComponent = rectComponent;
    PhysicsComponent_t* physicsComponent = (PhysicsComponent_t*) malloc(sizeof(PhysicsComponent_t));
    physicsComponent->acceleration.x = 0;
    physicsComponent->acceleration.y = 0;
    physicsComponent->velocity.x = 0;
    physicsComponent->velocity.y = 0;
    physicsComponent->friction = 0;
    entity->components.physicsComponent = physicsComponent;
    entity->flags = ENT_IS_COLLIDING;


    return entity;
}

void ENT_FreeEntity(Entity_t* ent){
    free(ent->components.physicsComponent);
    free(ent->components.rectComponent);
    free(ent->components.textureComponent);
    free(ent->components.transformComponent);
}
