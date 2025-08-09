//
// Created by eal on 11/25/24.
//

#include "SceneController.h"

#include <iostream>
#include <utility>

SceneController::SceneController(std::shared_ptr<IGraphicsLibrary> graphicsLibrary) : graphicsInterface_(
        std::move(graphicsLibrary)), currentDeltaTime_(0), updates_(0)
{
    drawAbleControllers_.emplace_back(std::make_shared<DrawAbleController>());
}

void SceneController::startDrawing() const
{
    while (not graphicsInterface_->toCloseWindow())
    {
        auto offset = drawAbleControllers_[0]->getOffsetForDrawing();
        graphicsInterface_->draw(drawAbleControllers_[0]->getDrawAbles(), offset.first, offset.second,
                                 updatesLastSecond_.load());
        drawAbleControllers_[0]->drawingLoopDone();
    }
    graphicsInterface_->cleanUpContext();
}

void SceneController::updateDone(double deltaTime)
{
    drawAbleControllers_[0]->updateLoopDone(graphicsInterface_->getWindowSize());
    currentDeltaTime_ += deltaTime;
    updates_++;
    if (currentDeltaTime_ > 1)
    {
        updatesLastSecond_.store(updates_ * currentDeltaTime_);
        currentDeltaTime_ = 0;
        updates_ = 0;
    }
}

std::shared_ptr<DrawAbleController>& SceneController::getCurrentDrawAbleController()
{
    return drawAbleControllers_[0];
}
