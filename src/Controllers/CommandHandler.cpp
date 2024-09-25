//
// Created by Elias on 25/09/2024.
//

#include "CommandHandler.h"


std::weak_ptr<DrawAble> CommandHandler::addDrawAble()
{
    std::lock_guard<std::shared_mutex> lock(drawAbleMutex_);
    auto drawAble = std::make_shared<DrawAble>();
    drawAbles_.emplace_back(drawAble);
    drawAble->id((int) drawAbles_.size() - 1);
    return {drawAble};
}

std::weak_ptr<DrawAble> CommandHandler::getDrawAble(int id)
{
    std::shared_lock<std::shared_mutex> lock(drawAbleMutex_);
    return drawAbles_[id];
}
