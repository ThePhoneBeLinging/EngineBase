//
// Created by eal on 11/25/24.
//

#include "SceneController.h"

#include <utility>

SceneController::SceneController(std::shared_ptr<IGraphicsLibrary> graphicsLibrary) : graphicsInterface_(
        std::move(graphicsLibrary))
{
    drawAbleControllers_.emplace_back(std::make_shared<DrawAbleController>());
}

void SceneController::startDrawing() const
{
    while (not graphicsInterface_->toCloseWindow())
    {
        auto offset = drawAbleControllers_[0]->getOffsetForDrawing();
        graphicsInterface_->draw(drawAbleControllers_[0]->getDrawAbles(), offset.first, offset.second);
        drawAbleControllers_[0]->drawingLoopDone();
    }
    graphicsInterface_->closeWindow();
}

void SceneController::updateDone()
{
    drawAbleControllers_[0]->updateLoopDone(graphicsInterface_->getWindowSize());
}

std::shared_ptr<DrawAbleController>& SceneController::getCurrentDrawAbleController()
{
    return drawAbleControllers_[0];
}

std::pair<double, double> SceneController::getOffset()
{
    return drawAbleControllers_[0]->getCurrentUpdateOffset();
}
