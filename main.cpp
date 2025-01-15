#include <iostream>
#include "framework/graphics/OpenGLApplication.h"

void main(){
    printf("Hello TinyEngine!\n");

    TinyEngine::OpenGLApplication G_App(800, 600);
    int code;
    if((code = G_App.onInit()) != 0){
        printf("onInit failed, code: %d\n", code);
        return;
    }
    while(!G_App.isExit()){
        G_App.onTick();
    }

    G_App.onExit();

    return;
}