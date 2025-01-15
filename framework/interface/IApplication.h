#pragma once
#ifndef IAPPLICATION_H
#define IAPPLICATION_H

#include "Interface.h"
#include "IRuntimeModule.h"

namespace TinyEngine{
    Interface IApplication {
        public:
            virtual int onInit() = 0;
            virtual void onExit() = 0;
            virtual void onTick() = 0;
            virtual bool isExit() = 0;
    };
}

#endif