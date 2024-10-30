//
// Created by eal on 10/30/24.
//

#include "DrawAbleObjects.h"

int* DrawAbleObjects::addDrawAble(const std::shared_ptr<DrawAble>& drawAble)
{
    drawAbles_.push_back(drawAble);
    drawAbleIds_.push_back(static_cast<int>(drawAbles_.size()) - 1);
    activeDrawAbles_.push_back(drawAble);
    return &drawAbleIds_.back();
}

void DrawAbleObjects::markDrawAbleAsOnScreen(const int id)
{
    activeDrawAbles_.push_back(drawAbles_.at(id));
}

void DrawAbleObjects::markDrawAbleAsOffScreen(const int id)
{
    activeDrawAbles_.remove(drawAbles_.at(id));
}

void DrawAbleObjects::removeDrawAble(const int id)
{
    activeDrawAbles_.remove(drawAbles_.at(id));
    drawAbles_.erase(drawAbles_.begin() + id);
}


