#include "managers/windowManager.h"

#include <GLFW/glfw3.h>
#include <string>

#include "log.h"

GLFWwindow* WindowManager::createWindow(int width, int height, std::string title){
    m_window = glfwCreateWindow(width,height,title.c_str(),NULL,NULL);
    glfwMakeContextCurrent(m_window);
    if(!m_window){
        err << "Failed to create a window !\n";
        glfwTerminate();
        exit(-1);
    }
    return m_window;
}

GLFWwindow* WindowManager::getWindow(){
    return m_window;
}

void WindowManager::changeTitle(std::string title){
    glfwSetWindowTitle(m_window,title.c_str());
}

GLFWwindow* WindowManager::m_window = nullptr;