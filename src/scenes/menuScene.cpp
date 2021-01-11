#include "scenes/menuScene.h"

#include "log.h"
#include "managers/manager.h"
#include "components/transformComponent.h"
#include "systems/meshLoadingSystem.h"


void MenuScene::start(){
    log<<"MenuScene has started \n";
    // Entity* entity0 = new Entity();
    // Entity* entity1 = new Entity();
    // Manager::addEntity(entity0);
    // Manager::addEntity(entity1);

    // TransformComponent* tc= new TransformComponent;
    // TransformComponent* td= new TransformComponent;
    // tc->x = 420;
    // td->x = 68;
    // Manager::addComponent(entity0,tc);
    // Manager::addComponent(entity1,td);

    // for(auto&i : Manager::getComponents(Component::getType<TransformComponent>())){
    //     TransformComponent* test = (TransformComponent*)i;
    //     log<<test->x<<"\n";
    // }
    Manager::addSystem(new MeshLoadingSystem());

    for(const auto&i : Manager::getSystems()){
        i->start();
    }
}

void MenuScene::update(){
    for(const auto&i : Manager::getSystems()){
        i->update();
    }
}

void MenuScene::render(){
    for(const auto&i : Manager::getSystems()){
        i->render();
    }
}

void MenuScene::clean(){
    Manager::clean();
}