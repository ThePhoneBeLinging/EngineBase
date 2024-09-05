//
// Created by Elias Aggergaard Larsen on 01/09/2024.
//

#include <iostream>

#include "EngineBase/EngineBase.h"
#include "SampleClient.h"
#include "SampleObject.h"

int main()
{
    EngineBase::loadTexture("Textures/zelda.png");
    auto otherObject = std::make_shared<SampleObject>();
    otherObject->textureIndex(1);
    auto sampleClient = std::make_shared<SampleClient>();
    EngineBase::startGUI(SampleClient::update);
    std::cout << "Hello world!" << std::endl;
    return 0;
}

