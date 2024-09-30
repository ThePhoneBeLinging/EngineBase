//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include <algorithm>
#include "ObjectController.h"
#include "TextureController.h"
#include "EngineBase/Command.h"
#include "EngineBase/EngineBase.h"

void ObjectController::update(float deltaTime)
{
    handleClicks();
    updateSpeedAbles(deltaTime);
}

void ObjectController::addDrawAble(int id)
{
    std::lock_guard<std::mutex> lock(drawAblesMutex);
    drawAbles_.push_back(id);
}

void ObjectController::addDragAble(const std::weak_ptr<DragAble> &dragAble)
{
    dragAbles_.push_back(dragAble);
    sortDragAbles();
}

void ObjectController::addSpeedAble(const std::weak_ptr<SpeedAble> &speedAble)
{
    speedAbles_.push_back(speedAble);
}


void ObjectController::addClickAble(const std::weak_ptr<ClickAble> &clickAble)
{
    clickAbles_.push_back(clickAble);
    sortClickAbles();
}

void ObjectController::drawObjects()
{
    std::unique_lock<std::mutex> lock(drawAblesMutex);
    auto drawAbles = drawAbles_;
    lock.unlock();
    TextureController::startDrawing();
    for (const auto &drawAble: drawAbles_)
    {
        auto drawAblePtr = ObjectKeeper::getDrawAbleForReading(drawAble);
        if (drawAblePtr != nullptr)
        {
            drawAblePtr->draw();
        }
    }
    TextureController::endDrawing();
}

void ObjectController::handleClicks()
{
    //TODO Extract this to an interface
    auto mousePos = GetMousePosition();
    if (EngineBase::mouseButtonPressed(ENGINEBASE_BUTTON_LEFT))
    {
        if (currentDragged_ != nullptr)
        {
            auto currentDraggedPtr = currentDragged_->lock();
            if (currentDraggedPtr != nullptr)
            {
                currentDraggedPtr->updateDrag(mousePos.x, mousePos.y);
            }
        }
        else
        {
            for (auto &dragAble: dragAbles_)
            {
                auto dragAblePtr = dragAble.lock();
                if (dragAblePtr == nullptr)
                {
                    continue;
                }
                if (dragAblePtr->getDrawAble()->isPointInside(mousePos.x, mousePos.y))
                {
                    dragAblePtr->startDrag(mousePos.x, mousePos.y);
                    currentDragged_ = &dragAble;
                    break;
                }
            }
        }

        for (const auto &clickAble: clickAbles_)
        {
            auto clickAblePtr = clickAble.lock();
            if (clickAblePtr == nullptr)
            {
                continue;
            }
            if (clickAblePtr->drawAble()->isPointInside(mousePos.x, mousePos.y))
            {
                clickAblePtr->onClick();
                break;
            }
        }
    }
    else
    {
        if (currentDragged_ != nullptr)
        {
            currentDragged_ = nullptr;
        }
    }
}

void ObjectController::updateSpeedAbles(float deltaTime)
{
    for (const auto &speedAble: speedAbles_)
    {
        auto speedAblePtr = speedAble.lock();
        if (speedAblePtr != nullptr)
        {
            speedAblePtr->update(deltaTime);
        }
    }
}

void ObjectController::sortDrawAbles()
{
    std::ranges::sort(drawAbles_, [](const int &a, const int &b)
    {
        auto aPtr = ObjectKeeper::getDrawAbleForReading(a);
        auto bPtr = ObjectKeeper::getDrawAbleForReading(b);
        return aPtr->z() < bPtr->z();
    });
}

void ObjectController::sortDragAbles()
{
    std::erase_if(dragAbles_, [](const std::weak_ptr<DragAble> &ptr)
    {
        return ptr.expired();
    });
    std::ranges::sort(dragAbles_, [](const std::weak_ptr<DragAble> &a, const std::weak_ptr<DragAble> &b)
    {
        auto aPtr = a.lock();
        auto bPtr = b.lock();
        if (aPtr == nullptr || bPtr == nullptr)
        {
            return false;
        }
        return aPtr->getDrawAble()->z() > bPtr->getDrawAble()->z();
    });
}

void ObjectController::sortClickAbles()
{
    std::erase_if(clickAbles_, [](const std::weak_ptr<ClickAble> &ptr)
    {
        return ptr.expired();
    });
    std::ranges::sort(clickAbles_, [](const std::weak_ptr<ClickAble> &a, const std::weak_ptr<ClickAble> &b)
    {
        auto aPtr = a.lock();
        auto bPtr = b.lock();
        if (aPtr == nullptr || bPtr == nullptr)
        {
            return false;
        }
        return aPtr->drawAble()->z() > bPtr->drawAble()->z();
    });
}

void ObjectController::keepDrawing()
{
    while (!WindowShouldClose())
    {
        drawObjects();
    }
}

