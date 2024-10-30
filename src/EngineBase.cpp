//
// Created by eal on 10/24/24.
//

#include "EngineBase/EngineBase.h"

#include "DrawAbleObjects.h"
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

void EngineBase::addDrawAble(const std::shared_ptr<DrawAble>& drawAble)
{
    DrawAbleObjects::addDrawAble(drawAble);
}

std::pair<int, int> EngineBase::getWindowSize()
{
    return graphicsInterface_->getWindowSize();
}
