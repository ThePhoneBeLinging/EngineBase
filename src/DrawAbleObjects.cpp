//
// Created by eal on 10/30/24.
//

#include "DrawAbleObjects.h"

void DrawAbleObjects::addDrawAble(const std::shared_ptr<DrawAble>& drawAble)
{
    drawAbles_.push_back(drawAble);
    drawAbleIds_.push_back(static_cast<int>(drawAbles_.size()) - 1);
    activeDrawAbles_.push_back(drawAble);
    drawAble->setID(&drawAbleIds_.back());
}

void DrawAbleObjects::markDrawAbleAsOnScreen(const int id)
{
    activeDrawAbles_.push_back(drawAbles_.at(id));
    sortActiveDrawAbles();
}

void DrawAbleObjects::markDrawAbleAsOffScreen(const int id)
{
    activeDrawAbles_.remove(drawAbles_.at(id));
}

std::list<std::shared_ptr<DrawAble>>& DrawAbleObjects::getActiveDrawAbles()
{
    return activeDrawAbles_;
}

void DrawAbleObjects::removeDrawAble(const int id)
{
    // TODO Remove from DrawAbles list, and use a first-fit when adding drawAbles
    activeDrawAbles_.remove(drawAbles_.at(id));
}

void DrawAbleObjects::sortActiveDrawAbles()
{
    activeDrawAbles_.sort([] (const std::shared_ptr<DrawAble> &firstDrawAble, const std::shared_ptr<DrawAble> &secondDrawAble) {return firstDrawAble->getZ() >= secondDrawAble->getZ();});
}


