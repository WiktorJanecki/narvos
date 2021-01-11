#pragma once

#include <vector>
#include <GL/glew.h>

#include "systems/system.h"


class MeshLoadingSystem : public System{
    public:
        void start() override;
        void update() override;
        void render() override;
        virtual ~MeshLoadingSystem();

    private:
        std::vector<GLuint> m_vaos = {};
        std::vector<GLuint> m_vbos = {};

        void storeDataInAttributeList(GLuint attributeNumber,GLint coordinateSize, std::vector<float> data);
};