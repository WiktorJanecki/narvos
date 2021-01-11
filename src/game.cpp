#include "game.h"

#include <iostream>

#include "log.h"
#include "definitions.h"
#include "managers/windowManager.h"
#include "managers/sceneManager.h"
#include "scenes/menuScene.h"


void Game::start(){
    log << "\n Narvos has started \n ";                  //log starting game info
    if(DEBUG){warn << "Game started in debug mode\n ";}
    log << "Version: " << VERSION << "\n\n";

    if (!glfwInit()){
        err << "Failed to init GLFW\n";
        exit(-1);
    }                                                    //end 

    WindowManager::createWindow(1280,720,"Narvos");

    SceneManager::initScene(new MenuScene());

    while(!glfwWindowShouldClose(WindowManager::getWindow())){
        update();
        render();
    }
}

void Game::update(){
    glfwPollEvents();
    SceneManager::getCurrentScene()->update();
}

void Game::render(){
    glClear(GL_COLOR_BUFFER_BIT);
    SceneManager::getCurrentScene()->render();
    glfwSwapBuffers(WindowManager::getWindow());
}
