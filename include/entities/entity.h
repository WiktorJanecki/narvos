#pragma once

#include <vector>

#include "components/component.h"


class Entity{
    public:
        int getID();
    private:
        int m_id = -1;
        std::vector<Component*> m_components = {}; 

        void setID(int id);

    friend class Manager;
};