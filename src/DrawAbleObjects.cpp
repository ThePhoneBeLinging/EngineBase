//
// Created by eal on 10/30/24.
//

#include "DrawAbleObjects.h"

void DrawAbleObjects::addDrawAble(const std::shared_ptr<DrawAble>& drawAble)
{
    drawAbles_.push_back(drawAble);
    activeDrawAbles_.push_back(drawAble);
}

void DrawAbleObjects::markDrawAbleAsOnScreen(const std::shared_ptr<DrawAble>& drawAble)
{
    activeDrawAbles_.push_back(drawAble);
}

void DrawAbleObjects::removeDrawAble(const std::shared_ptr<DrawAble>& drawAble)
{
    activeDrawAbles_.remove(drawAble);
    offScreenDrawAbles_.remove(drawAble);
    drawAbles_.remove(drawAble);
}

void DrawAbleObjects::markDrawAbleAsOffScreen(const std::shared_ptr<DrawAble>& drawAble)
{
    activeDrawAbles_.remove(drawAble);
    offScreenDrawAbles_.push_back(drawAble);
}
