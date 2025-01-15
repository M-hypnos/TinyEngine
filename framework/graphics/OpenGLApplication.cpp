#include "OpenGLApplication.h"
#include <iostream>

using namespace TinyEngine;

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

int OpenGLApplication::onInit(){

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    window = glfwCreateWindow(m_width, m_height, "TinyEngine", NULL, NULL);
    if(window == nullptr){
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD\n");
        return -1;
    }    
    return 0;
}

void OpenGLApplication::onExit(){
    glfwTerminate();
}

void OpenGLApplication::onTick(){
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool OpenGLApplication::isExit(){
    return glfwWindowShouldClose(window);
}