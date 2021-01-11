#include "systems/renderingSystem.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "managers/manager.h"
#include "components/meshComponent.h"

void RenderingSystem::start(){}

void RenderingSystem::update(){}

void RenderingSystem::render(){
    for(auto&i : Manager::getComponents(Component::getType<MeshComponent>())){
        MeshComponent* component = (MeshComponent*)i;
        glBindVertexArray(component->vaoID);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glDrawElements(GL_TRIANGLES,component->indices.size(),GL_UNSIGNED_INT,0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(0);
        glBindVertexArray(0);
    }
}
