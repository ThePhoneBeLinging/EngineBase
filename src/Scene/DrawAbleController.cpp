//
// Created by Elias Aggergaard Larsen on 08/12/2024.
//

#include "DrawAbleController.h"

DrawAbleController::DrawAbleController() : activeDrawingIndex_(0), nextDrawingIndex_(0), updatingIndex_(1),
                                           updateOffset_(0, 0)
{
    // initialise one list for drawing and one for the updateLoop
    for (int i = 0; i < 3; i++)
    {
        sharedDrawAbles_.emplace_back();
        offsets_.emplace_back(0, 0);
    }
}

void DrawAbleController::addDrawAble(const std::weak_ptr<DrawAble> &drawAble)
{
    weakDrawAbles_.push_back(drawAble);
}

void DrawAbleController::updateLoopDone()
{
    sharedDrawAbles_[updatingIndex_].clear();
    sharedDrawAbles_[updatingIndex_].reserve(weakDrawAbles_.size());

    for (const auto &drawAble: weakDrawAbles_)
    {
        if (not drawAble.expired())
        {
            const auto sDrawAble = drawAble.lock();
            if (drawAbleOnScreen(sDrawAble))
            {
                sharedDrawAbles_[updatingIndex_].emplace_back(std::make_unique<DrawAble>(drawAble.lock().get()));
            }
        }
    }
    std::unique_lock lock(mutex_);
    nextDrawingIndex_ = updatingIndex_;
    lock.unlock();
    while (updatingIndex_ == activeDrawingIndex_ || updatingIndex_ == nextDrawingIndex_)
    {
        updatingIndex_++;
        updatingIndex_ %= 3;
    }
}

void DrawAbleController::drawingLoopDone()
{
    std::lock_guard lock(mutex_);
    activeDrawingIndex_ = nextDrawingIndex_;
}

std::vector<std::unique_ptr<DrawAble>> &DrawAbleController::getDrawAbles()
{
    return sharedDrawAbles_[activeDrawingIndex_];
}

bool DrawAbleController::drawAbleOnScreen(const std::shared_ptr<DrawAble> &drawAble)
{
    //TODO be dynamic
    int screenHeight = 800;
    int screenWidth = 1200;

    if (not drawAble->getPositionIsAffectedByOffset())
    {
    }
    else
    {
        if (drawAble->getX() + drawAble->getWidth() < 0 || screenWidth < drawAble->getX())
        {
            return false;
        }
        if (drawAble->getY() + drawAble->getHeight() < 0 || screenHeight < drawAble->getY())
        {
            return false;
        }
        return true;
    }
    return false;
}
