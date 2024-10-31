//
// Created by eal on 10/24/24.
//

#include "EngineBase/EngineBase.h"

#include "DrawAbleObjects.h"
#include "UpdateController.h"
#include "GraphicsInterface/RayLibImplementation.h"

void EngineBase::init()
{
    graphicsInterface_ = new RayLibImplementation();
    graphicsInterface_->init();
}

void EngineBase::addDrawAble(const std::shared_ptr<DrawAble>& drawAble)
{
    DrawAbleObjects::addDrawAble(drawAble);
}

void EngineBase::registerUpdateFunction(const std::function<void(double deltaTime)>& updateFunction)
{
    UpdateController::registerUpdateFunction(updateFunction);
}

IGraphicsLibrary* EngineBase::getGraphicsLibrary()
{
    return graphicsInterface_;
}
