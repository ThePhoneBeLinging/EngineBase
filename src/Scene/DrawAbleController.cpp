//
// Created by Elias Aggergaard Larsen on 08/12/2024.
//

#include "DrawAbleController.h"

#include <algorithm>

DrawAbleController::DrawAbleController() : activeDrawingIndex_(0), nextDrawingIndex_(0),
                                           updatingIndex_(1),
                                           updateOffset_(0, 0)
{
    // initialise one list for drawing and one for the updateLoop
    for (int i = 0; i < 3; i++)
    {
        sharedDrawAbles_.emplace_back();
        offsets_.emplace_back(0, 0);
    }
}

void DrawAbleController::addDrawAble(const std::weak_ptr<DrawAble>& drawAble)
{
    weakDrawAbles_.push_back(drawAble);
}

void DrawAbleController::updateLoopDone(std::pair<int, int> windowSize)
{
    sharedDrawAbles_[updatingIndex_].clear();
    sharedDrawAbles_[updatingIndex_].reserve(weakDrawAbles_.size());
    offsets_[updatingIndex_] = std::pair(updateOffset_);

    for (const auto& drawAble : weakDrawAbles_)
    {
        if (not drawAble.expired())
        {
            const auto sDrawAble = drawAble.lock();
            if (isDrawAbleOnScreen(sDrawAble, windowSize.first, windowSize.second))
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

std::vector<std::unique_ptr<DrawAble>>& DrawAbleController::getDrawAbles()
{
    auto comparator = [](const std::unique_ptr<DrawAble>& lhs, const std::unique_ptr<DrawAble>& rhs) {
        return lhs->getZ() < rhs->getZ();
    };
    // The code below brought me from 3k fps to 2k, also, no reason to sort unless changes have been made to z-values.
    // TODO TLDR, update code below if performance issues...
    std::sort(sharedDrawAbles_[activeDrawingIndex_].begin(), sharedDrawAbles_[activeDrawingIndex_].end(), comparator);
    return sharedDrawAbles_[activeDrawingIndex_];
}

bool
DrawAbleController::isDrawAbleOnScreen(const std::shared_ptr<DrawAble>& drawAble, int screenWidth, int screenHeight)
{
    int drawAbleX = drawAble->getX();
    int drawAbleY = drawAble->getY();

    if (drawAble->getPositionIsAffectedByOffset())
    {
        drawAbleX += updateOffset_.first;
        drawAbleY += updateOffset_.second;
    }

    if (drawAbleX + drawAble->getWidth() < 0 ||
        screenWidth < drawAbleX)
    {
        return false;
    }
    if (drawAbleY + drawAble->getHeight() < 0 ||
        screenHeight < drawAbleY)
    {
        return false;
    }
    return true;
}

std::pair<int, int> DrawAbleController::getOffsetForDrawing()
{
    return offsets_[activeDrawingIndex_];
}

void DrawAbleController::setOffset(double offsetX, double offsetY)
{
    updateOffset_.first = offsetX;
    updateOffset_.second = offsetY;
}

void DrawAbleController::updateOffset(double deltaOffsetX, double deltaOffsetY)
{
    updateOffset_.first += deltaOffsetX;
    updateOffset_.second += deltaOffsetY;
}

std::pair<double, double> DrawAbleController::getCurrentUpdateOffset()
{
    return updateOffset_;
}
