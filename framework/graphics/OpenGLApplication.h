#pragma once
#ifndef OPENGLAPPLICATION_H
#define OPENGLAPPLICATION_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../common/BaseApplication.h"

namespace TinyEngine{
    class OpenGLApplication :public BaseApplication{
        public:
            OpenGLApplication(int width, int height):BaseApplication(width, height){};
            int onInit() override;
            void onExit() override;
            void onTick() override;
            virtual bool isExit() override;
        private:
            GLFWwindow* window;
    };
}

#endif