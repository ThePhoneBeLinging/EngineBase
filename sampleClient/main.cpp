//
// Created by Elias Aggergaard Larsen on 01/09/2024.
//

#include <iostream>

#include "EngineBase/EngineBase.h"

void update(float delta)
{
    std::cout << "Delta: " << delta << std::endl;
}

int main()
{
    EngineBase::addDrawAble();
    //EngineBase::loadTexture("Textures/zelda.png");
    //EngineBase::startGUI(update);

    std::cout << "Hello world!" << std::endl;
    return 0;
}

