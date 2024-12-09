//
// Created by eal on 11/25/24.
//

#include "Scene.h"

Scene::Scene() : drawAbleController_(std::make_unique<DrawAbleController>())
{
}

void Scene::addDrawAbleToScene(const std::weak_ptr<DrawAble> &drawAble)
{
    drawAbleController_->addDrawAble(drawAble);
}

void Scene::drawingDone()
{
    drawAbleController_->drawingLoopDone();
}

void Scene::updateDone()
{
    drawAbleController_->updateLoopDone();
}

std::vector<std::unique_ptr<DrawAble>> &Scene::getDrawables() const
{
    return drawAbleController_->getDrawAbles();
}

std::pair<int, int> Scene::getOffsetForDrawing()
{
    return drawAbleController_->getOffsetForDrawing();
}
