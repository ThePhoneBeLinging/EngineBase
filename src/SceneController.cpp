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
    }
    graphicsInterface_->closeWindow();
}

std::shared_ptr<Scene> SceneController::getScene(const int scene)
{
    return scenes_[scene];
}
