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
    EngineBase::executeCommand({PrimaryCMD::UPDATE, ObjectType::DRAWABLE, 0, SecondaryCMD::WIDTH, 50});
    EngineBase::executeCommand({PrimaryCMD::UPDATE, ObjectType::DRAWABLE, 0, SecondaryCMD::HEIGHT, 50});
    EngineBase::executeCommand(Command(PrimaryCMD::DONEWRITING));
}

int main()
{
    EngineBase::addDrawAble();
    EngineBase::executeCommand(Command(PrimaryCMD::DONEWRITING));
    EngineBase::loadTexture("Textures/zelda.png");
    EngineBase::startGUI(update);

    std::cout << "Hello world!" << std::endl;
    return 0;
}

