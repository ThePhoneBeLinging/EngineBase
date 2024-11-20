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
    std::thread thread(&UpdateController::startUpdateLoop, updateController_);
    thread.join();
    graphicsInterface_->closeWindow();
}

void EngineBase::registerDrawAble(const std::shared_ptr<DrawAble>& drawAble)
{
    drawAble_.push_back(drawAble->getDrawAblePtr());
}

void EngineBase::registerUpdateFunction(const std::function<void(double deltaTime)>& updateFunction) const
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
