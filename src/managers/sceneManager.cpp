#include "managers/sceneManager.h"

#include "scenes/scene.h"

void SceneManager::initScene(Scene* scene){
    m_currentScene = scene;
    m_currentScene->start();
}

void SceneManager::changeScene(Scene* nextScene){
    m_currentScene->clean();
    delete m_currentScene;
    m_currentScene = nextScene;
    m_currentScene->start();
}

Scene* SceneManager::getCurrentScene(){
    return m_currentScene;
}

Scene* SceneManager::m_currentScene = nullptr;