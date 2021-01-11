#include "managers/manager.h"

#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>

#include "components/component.h"
#include "entities/entity.h"
#include "systems/system.h"


void Manager::addEntity(Entity* entity){
    entity->setID(generateID());
    m_entities.push_back(entity);
}

void Manager::removeEntity(Entity* entity){
    auto it = std::find(m_entities.begin(),m_entities.end(), entity);
    if(it == m_entities.end()){
        throw "Cannot remove entity which does not exist";
    }
    m_entities.erase(it);
}

std::vector<Entity*> Manager::getEntitiesWith(std::string type){
    std::vector<Entity*> list = {};
    for(const auto&i : m_entities){
        if(hasComponent(i,type)){
            list.push_back(i);
        }
    }
    return list;
}

void Manager::addComponent(Entity* targetEntity, Component* component){
    targetEntity->m_components.push_back(component);
}

void Manager::removeComponent(Entity*targetEntity, std::string type){
    Component* component = getComponent(targetEntity,type);
    auto it=std::find(targetEntity->m_components.begin(),targetEntity->m_components.end(),component);
    if(it == targetEntity->m_components.end()){
        throw "Cannot remove "+type+"component because it does not exist in entity of id " + std::to_string(targetEntity->getID());
    }
    targetEntity->m_components.erase(it);
}

Component* Manager::getComponent(Entity* targetEntity, std::string type){
    for(auto&i : targetEntity->m_components){
        if(i->getType() == type){
            return i;
        }
    }
    throw "Cannot get "+type+" component because it does not exist in entity of id "+ std::to_string(targetEntity->getID());
}

std::vector<Component*> Manager::getComponents(std::string type){
    std::vector<Component*> list = {};
    for(const auto&i : m_entities){
        for(auto&c : i->m_components){
            if(c->getType() == type){
                list.push_back(c);
            }
        }
    }
    return list;
}

bool Manager::hasComponent(Entity*targetEntity, std::string type){
    for(const auto&i : targetEntity->m_components){
        if(i->getType() == type){
            return true;
        }
    }
    return false;
}

void Manager::addSystem(System* system){
    m_systems.push_back(system);
}

void Manager::removeSystem(System* system){
    auto it = std::find(m_systems.begin(),m_systems.end(),system);
    if(it == m_systems.end()){
        throw "Cannot remove system that does not exist";
    }
    m_systems.erase(it);
}

std::vector<System*> Manager::getSystems(){
    return m_systems;
}

void Manager::clean(){
    for(auto&i : m_entities){
        delete i;
    }
    m_entities.clear();
    for(auto&i : m_systems){
        delete i;
    }
    m_systems.clear();
}

int Manager::generateID(){
    m_lastID++;
    return m_lastID-1;
}

std::vector<Entity*> Manager::m_entities = {};
std::vector<System*> Manager::m_systems = {};
int Manager::m_lastID = 0;