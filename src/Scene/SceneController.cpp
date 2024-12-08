//
// Created by eal on 11/25/24.
//

#include "SceneController.h"

#include <utility>

SceneController::SceneController(std::shared_ptr<IGraphicsLibrary> graphicsLibrary) : graphicsInterface_(
    std::move(graphicsLibrary))
{
    scenes_.emplace_back(std::make_shared<Scene>());
}

void SceneController::startDrawing() const
{
    while (not graphicsInterface_->toCloseWindow())
    {
        graphicsInterface_->draw(scenes_[0]);
        scenes_[0]->drawingDone();
    }
    graphicsInterface_->closeWindow();
}

void SceneController::drawingDone()
{
    scenes_[0]->drawingDone();
}

void SceneController::updateDone()
{
    scenes_[0]->updateDone();
}

std::shared_ptr<Scene> SceneController::getScene(const int scene)
{
    return scenes_[scene];
}
