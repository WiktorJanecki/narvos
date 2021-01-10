#pragma once

#include "scenes/scene.h"
#include "log.h"

class SceneManager{
    public:
        static void initScene(Scene* scene);
        static void changeScene(Scene* nextScene);
        static Scene* getCurrentScene();
    private:
        static Scene* m_currentScene;

};