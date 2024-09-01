//
// Created by Elias Aggergaard Larsen on 01/09/2024.
//

#include <iostream>

#include "EngineBase.h"
#include "SampleClient.h"
#include "SampleObject.h"

int main()
{
    EngineBase::loadTexture("Textures/MissingTexture.png");
    auto sampleClient = std::make_shared<SampleClient>();
    EngineBase::startGUI();
    std::cout << "Hello world!" << std::endl;
    return 0;
}