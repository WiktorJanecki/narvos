#include "systems/meshLoadingSystem.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "log.h"
#include "components/meshComponent.h"
#include "managers/manager.h"


void MeshLoadingSystem::start(){
    for(auto&i : Manager::getComponents(Component::getType<MeshComponent>())){
        MeshComponent* component = (MeshComponent*)i;
        GLuint vaoID;   //generate vao for mesh object
        glGenVertexArrays(4,&vaoID);
        glBindVertexArray(vaoID);   //enable setting things into this vao
        m_vaos.push_back(vaoID);  

        GLuint vboID;  // generate vbo into this vao
        glGenBuffers(1,&vboID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,component->indices.size() * sizeof(int),component->indices.data(),GL_STATIC_DRAW);
        m_vbos.push_back(vboID);

        storeDataInAttributeList(0,2,component->positions);     //generate vbo into this vao
        storeDataInAttributeList(1,2,component->textures);      //generate vbo into this vao
        
        glBindVertexArray(0);   //disable setting things into this vao

        component->vaoID = vaoID;
    }
}

void MeshLoadingSystem::update(){

}

void MeshLoadingSystem::render(){}

MeshLoadingSystem::~MeshLoadingSystem(){
    for(const auto&i : m_vaos){
        glDeleteVertexArrays(4,&i);
    }
    for(const auto&i : m_vbos){
        glDeleteBuffers(1,&i);
    }
}

void MeshLoadingSystem::storeDataInAttributeList(GLuint attributeNumber,GLint coordinateSize, std::vector<float> data){
    GLuint vboID;
    glGenBuffers(1,&vboID);
    glBindBuffer(GL_ARRAY_BUFFER,vboID);
    glBufferData(GL_ARRAY_BUFFER,data.size() * sizeof(float),data.data(),GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber,coordinateSize,GL_FLOAT,false,0,0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    m_vbos.push_back(vboID);
}