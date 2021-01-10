#pragma once

#include <vector>
#include <string>

#include "components/component.h"
#include "entities/entity.h"
#include "systems/system.h"


class Manager{
    public:
        void addEntity(Entity* entity);
        void removeEntity(Entity* entity);
        std::vector<Entity*> getEntitiesWith(std::string type);

        void addComponent(Entity* targetEntity, Component component);
        void removeComponent(Entity* targetEntity, std::string type);
        Component* getComponent(Entity* targetEntity, std::string type);
        std::vector<Component*> getComponents(std::string type);
        bool hasComponent(Entity* targetEntity, std::string type);

        void addSystem(System* system);
        void removeSystem(System* system);
        std::vector<System*> getSystems();

        //void listen(Listener* listener);
        //void initEvent(Event event);

        void clean();
    private:
        std::vector<Entity*> m_entities = {};
        std::vector<System*> m_systems = {};
        //std::vector<Listener*> m_listeners = {};
        int m_lastID = 0;

        int generateID();

};