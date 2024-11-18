//
// Created by eal on 10/24/24.
//

#include "EngineBase/EngineBase.h"
#include <thread>
#include "UpdateController.h"
#include "GraphicsInterface/RayLibImplementation.h"

EngineBase::EngineBase()
{
    graphicsInterface_ = std::make_shared<RayLibImplementation>();
    updateController_ = std::make_shared<UpdateController>(graphicsInterface_);
}

void EngineBase::launch()
{
    std::thread thread(&UpdateController::startUpdateLoop,updateController_);
    graphicsInterface_->startWindow();
    thread.join();
}

void EngineBase::addDrawAble(std::shared_ptr<DrawAble>& drawAble)
{
    auto newDrawAble = std::make_shared<DrawAble>(drawAble);
    drawAble->setDrawAble(newDrawAble);
    graphicsInterface_->addDrawAble(newDrawAble);
}

void EngineBase::registerUpdateFunction(const std::function<void(double deltaTime)>& updateFunction)
{
    updateController_->registerUpdateFunction(updateFunction);
}

std::shared_ptr<IGraphicsLibrary> EngineBase::getGraphicsLibrary()
{
    return graphicsInterface_;
}

std::shared_ptr<UpdateController> EngineBase::getUpdateController()
{
    return updateController_;
}
