//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include <algorithm>
#include "ObjectController.h"
#include "TextureController.h"

#include "EngineBase/EngineBase.h"

void ObjectController::update(float deltaTime)
{
    drawObjects();
    handleClicks();
    updateSpeedAbles(deltaTime);
}

void ObjectController::addDrawAble(const std::weak_ptr<DrawAble>& drawAble)
{
    drawAbles_.push_back(drawAble);
    sortDrawAbles();
}

void ObjectController::addDragAble(const std::weak_ptr<DragAble>& dragAble)
{
    dragAbles_.push_back(dragAble);
    sortDragAbles();
}

void ObjectController::addSpeedAble(const std::weak_ptr<SpeedAble>& speedAble)
{
    speedAbles_.push_back(speedAble);
}


void ObjectController::addClickAble(const std::weak_ptr<ClickAble>& clickAble)
{
    clickAbles_.push_back(clickAble);
    sortClickAbles();
}

void ObjectController::drawObjects()
{
    TextureController::startDrawing();
    for (const auto& drawAble : drawAbles_)
    {
        auto drawAblePtr = drawAble.lock();
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
            for (auto& dragAble : dragAbles_)
            {
                auto dragAblePtr = dragAble.lock();
                if (dragAblePtr == nullptr) continue;
                if (dragAblePtr->getDrawAble()->isPointInside(mousePos.x, mousePos.y))
                {
                    dragAblePtr->startDrag(mousePos.x, mousePos.y);
                    currentDragged_ = &dragAble;
                    break;
                }
            }
        }

        for (const auto& clickAble : clickAbles_)
        {
            auto clickAblePtr = clickAble.lock();
            if (clickAblePtr == nullptr) continue;
            if (clickAblePtr->drawAble()->isPointInside(mousePos.x, mousePos.y))
            {
                clickAblePtr->onClick();
                break;
            }
        }
    }
    else
    {
        if (currentDragged_ != nullptr) currentDragged_ = nullptr;
    }
}

void ObjectController::updateSpeedAbles(float deltaTime)
{
    for (const auto& speedAble : speedAbles_)
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
    std::vector<std::weak_ptr<DrawAble>> newDrawAbleList;
    for (const auto& drawAble : drawAbles_)
    {
        auto drawAblePtr = drawAble.lock();
        if (drawAblePtr != nullptr)
        {
            newDrawAbleList.push_back(drawAble);
        }
    }
    drawAbles_ = newDrawAbleList;
}

void ObjectController::sortDragAbles()
{
    std::erase_if(dragAbles_, [](const std::weak_ptr<DragAble>& ptr) { return ptr.expired(); });
    std::ranges::sort(dragAbles_, [](const std::weak_ptr<DragAble>& a, const std::weak_ptr<DragAble>& b)
    {
        auto aPtr = a.lock();
        auto bPtr = b.lock();
        if (aPtr == nullptr || bPtr == nullptr) return false;
        return aPtr->getDrawAble()->z() > bPtr->getDrawAble()->z();
    });
}

void ObjectController::sortClickAbles()
{
    std::erase_if(clickAbles_, [](const std::weak_ptr<ClickAble>& ptr) { return ptr.expired(); });
    std::ranges::sort(clickAbles_, [](const std::weak_ptr<ClickAble>& a, const std::weak_ptr<ClickAble>& b)
    {
        auto aPtr = a.lock();
        auto bPtr = b.lock();
        if (aPtr == nullptr || bPtr == nullptr) return false;
        return aPtr->drawAble()->z() > bPtr->drawAble()->z();
    });
}
