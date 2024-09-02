//
// Created by Elias Aggergaard Larsen on 01/09/2024.
//

#include <iostream>

#include "EngineBase/EngineBase.h"
#include "SampleClient.h"
#include "SampleObject.h"


static void updateFunction(float deltaTime)
{
    std::cout << "Update Called" << std::endl;
    std::cout << "Delta time: " << deltaTime << std::endl;
}

int main()
{
    EngineBase::loadTexture("Textures/MissingTexture.png");
    auto sampleClient = std::make_shared<SampleClient>();
    EngineBase::startGUI(updateFunction);
    std::cout << "Hello world!" << std::endl;
    return 0;
}

