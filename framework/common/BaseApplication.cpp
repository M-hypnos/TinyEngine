#include "BaseApplication.h"

using namespace TinyEngine;

int BaseApplication::onInit(){
    m_isExit = false;
    return 0;
}

void BaseApplication::onExit(){
 
}

void BaseApplication::onTick(){
    
}

bool BaseApplication::isExit(){
    return m_isExit;
}