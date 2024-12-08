//
// Created by Elias Aggergaard Larsen on 08/12/2024.
//

#include "DrawAbleController.h"

DrawAbleController::DrawAbleController() : activeDrawingIndex_(0), nextDrawingIndex_(0) ,updatingIndex_(1)
{
    // initialise one list for drawing and one for the updateLoop
    for (int i = 0; i < 3; i++)
    {
        sharedDrawAbles_.emplace_back();
    }
}

void DrawAbleController::addDrawAble(const std::weak_ptr<DrawAble>& drawAble)
{
    weakDrawAbles_.push_back(drawAble);
}

void DrawAbleController::updateLoopDone()
{
    sharedDrawAbles_[updatingIndex_].clear();
    sharedDrawAbles_[updatingIndex_].reserve(weakDrawAbles_.size());
    for (const auto& drawAble : weakDrawAbles_)
    {
        if (not drawAble.expired())
        {
            sharedDrawAbles_[updatingIndex_].push_back(drawAble.lock());
        }
    }
    nextDrawingIndex_ = updatingIndex_;
    while (updatingIndex_ == activeDrawingIndex_ || updatingIndex_ == nextDrawingIndex_)
    {
        updatingIndex_++;
        updatingIndex_ %= 3;
    }
}

void DrawAbleController::drawingLoopDone()
{
    activeDrawingIndex_ = nextDrawingIndex_;
}

std::vector<std::shared_ptr<DrawAble>>& DrawAbleController::getDrawAbles()
{
    return sharedDrawAbles_[activeDrawingIndex_];
}
