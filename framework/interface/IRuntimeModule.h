#pragma once
#include "Interface.h"

namespace TinyEngine{
    Interface IRuntimeModule{
        public:
            virtual  ~IRuntimeModule() = default;
            virtual int onInit() = 0;
            virtual void onExit() = 0;
            virtual void onTick() = 0;
    };
}
