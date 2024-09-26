//
// Created by Elias Aggergaard Larsen on 01/09/2024.
//

#include <iostream>
#include <Command/CommandEnums.h>
#include "EngineBase/Command.h"
#include "EngineBase/EngineBase.h"

void update(float delta)
{
    std::cout << "Delta: " << delta << std::endl;
}

int main()
{
    int drawAbleIndex = EngineBase::addDrawAble();
    EngineBase::executeCommand({PrimaryCMD::UPDATE, ObjectType::DRAWABLE, drawAbleIndex, SecondaryCMD::WIDTH, 50});
    EngineBase::executeCommand({PrimaryCMD::UPDATE, ObjectType::DRAWABLE, drawAbleIndex, SecondaryCMD::HEIGHT, 50});
    std::cout << drawAbleIndex << std::endl;
    EngineBase::loadTexture("Textures/zelda.png");
    EngineBase::startGUI(update);

    std::cout << "Hello world!" << std::endl;
    return 0;
}

