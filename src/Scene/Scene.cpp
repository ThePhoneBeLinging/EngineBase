//
// Created by eal on 11/25/24.
//

#include "Scene.h"

void Scene::addDrawAbleToScene(const std::weak_ptr<DrawAble>& drawAble)
{
    drawAbles_.push_back(drawAble);
}

std::vector<std::shared_ptr<DrawAble>> Scene::getDrawables() const
{
    std::vector<std::shared_ptr<DrawAble>> drawables;
    for (const auto& drawable : drawAbles_)
    {
        if (not drawable.expired())
        {
            drawables.push_back(drawable.lock());
        }
    }
    return drawables;
}
