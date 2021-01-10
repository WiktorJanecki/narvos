#pragma once

#include <GLFW/glfw3.h>
#include <string>

class WindowManager{
    public:
        static GLFWwindow* createWindow(int width, int height, std::string title);
        static GLFWwindow* getWindow();
        static void changeTitle(std::string title);
    private:
        static GLFWwindow* m_window;

};