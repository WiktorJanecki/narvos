#include "scenes/menuScene.h"

#include "log.h"
#include "managers/manager.h"
#include "components/transformComponent.h"

void MenuScene::start(){
    log<<"MenuScene has started \n";
    Entity* entity0 = new Entity();
    Entity* entity1 = new Entity();
    Manager::addEntity(entity0);
    Manager::addEntity(entity1);

    TransformComponent* tc= new TransformComponent;
    TransformComponent* td= new TransformComponent;
    tc->x = 420;
    td->x = 68;
    Manager::addComponent(entity0,tc);
    Manager::addComponent(entity1,td);

    for(auto&i : Manager::getComponents(Component::getType<TransformComponent>())){
        TransformComponent* test = (TransformComponent*)i;
        log<<test->x<<"\n";
    }
}

void MenuScene::update(){}

void MenuScene::render(){}

void MenuScene::clean(){}