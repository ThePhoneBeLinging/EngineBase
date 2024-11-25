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
    updateController_ = std::make_unique<UpdateController>(graphicsInterface_);
    sceneController_ = std::make_unique<SceneController>(graphicsInterface_);
}

void EngineBase::launch() const
{
    //std::thread thread(&UpdateController::startUpdateLoop, updateController_);
    sceneController_->startDrawing();
}

void EngineBase::registerDrawAble(const std::shared_ptr<DrawAble>& drawAble)
{
    sceneController_->getScene(0)->addDrawAbleToScene(drawAble);
}

void EngineBase::registerUpdateFunction(const std::function<void(double deltaTime)>& updateFunction) const
{
    updateController_->registerUpdateFunction(updateFunction);
}

std::shared_ptr<IGraphicsLibrary> EngineBase::getGraphicsLibrary()
{
    return graphicsInterface_;
}
