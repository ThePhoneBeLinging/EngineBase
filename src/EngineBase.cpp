//
// Created by eal on 10/24/24.
//

#include "EngineBase/EngineBase.h"

#include "GraphicsInterface/RayLibImplementation.h"

void EngineBase::init()
{
    graphicsInterface_ = new RayLibImplementation();
    graphicsInterface_->init();
}

std::pair<int, int> EngineBase::getMousePos()
{
    return graphicsInterface_->getMousePos();
}

int EngineBase::loadTexture(const std::string& texturePath)
{
    return graphicsInterface_->loadTexture(texturePath);
}
