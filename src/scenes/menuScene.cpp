#include "scenes/menuScene.h"

#include "log.h"
#include "managers/manager.h"
#include "components/transformComponent.h"
#include "components/meshComponent.h"
#include "systems/meshLoadingSystem.h"
#include "systems/renderingSystem.h"


void MenuScene::start(){
    log<<"MenuScene has started \n";
    Entity* entity0 = new Entity();
    Manager::addEntity(entity0);

    MeshComponent* mc = new MeshComponent();
    mc->positions = { 0,1,
                      1,-1,
                      -1,-1};
    mc->indices = {0,1,2};
    Manager::addComponent(entity0,mc);

    Manager::addSystem(new MeshLoadingSystem());
    Manager::addSystem(new RenderingSystem());
    
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
