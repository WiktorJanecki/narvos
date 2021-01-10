#pragma once

#include <vector>
#include <string>

#include "components/component.h"
#include "entities/entity.h"
#include "systems/system.h"


class Manager{
    public:
        static void addEntity(Entity* entity);
        static void removeEntity(Entity* entity);
        static std::vector<Entity*> getEntitiesWith(std::string type);

        static void addComponent(Entity* targetEntity, Component* component);
        static void removeComponent(Entity* targetEntity, std::string type);
        static Component* getComponent(Entity* targetEntity, std::string type);
        static std::vector<Component*> getComponents(std::string type);
        static bool hasComponent(Entity* targetEntity, std::string type);

        static void addSystem(System* system);
        static void removeSystem(System* system);
        static std::vector<System*> getSystems();

        //void listen(Listener* listener);
        //void initEvent(Event event);

        void clean();
    private:
        static std::vector<Entity*> m_entities;
        static std::vector<System*> m_systems;
        //std::vector<Listener*> m_listeners = {};
        static int m_lastID;

        static int generateID();

};