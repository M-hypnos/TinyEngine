#pragma once
#ifndef BASEAPPLICATION_H
#define BASEAPPLICATION_H

#include "../interface/IApplication.h"

namespace TinyEngine
{
    class BaseApplication:implements IApplication{
        public:
            BaseApplication(int width, int height):m_width(width),m_height(height),m_isExit(false){}
            virtual int onInit();
            virtual void onExit();
            virtual void onTick();
            virtual bool isExit();
        protected:
            bool m_isExit;
            int m_width;
            int m_height;
    };
} // namespace TinyEngine


#endif