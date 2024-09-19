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
        if (auto objectToDraw = drawAble.lock())
        {
            objectToDraw->draw();
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
            currentDragged_->lock()->updateDrag(mousePos.x, mousePos.y);
        }
        else
        {
            for (auto& dragAble : dragAbles_)
            {
                if (dragAble.lock()->getDrawAble()->isPointInside(mousePos.x, mousePos.y))
                {
                    dragAble.lock()->startDrag(mousePos.x, mousePos.y);
                    currentDragged_ = &dragAble;
                    break;
                }
            }
        }

        for (const auto& clickAble : clickAbles_)
        {
            if (clickAble.lock()->drawAble()->isPointInside(mousePos.x, mousePos.y))
            {
                clickAble.lock()->onClick();
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
        speedAble.lock()->update(deltaTime);
    }
}

void ObjectController::sortDrawAbles()
{
    std::ranges::sort(drawAbles_, [](const std::weak_ptr<DrawAble>& a, const std::weak_ptr<DrawAble>& b)
    {
        return a.lock()->z() <= b.lock()->z();
    });
}

void ObjectController::sortDragAbles()
{
    std::ranges::sort(
        dragAbles_, [](const std::weak_ptr<DragAble>& a, const std::weak_ptr<DragAble>& b)
        {
            return a.lock()->getDrawAble()->z() > b.lock()->getDrawAble()->z();
        });
}

void ObjectController::sortClickAbles()
{
    std::ranges::sort(clickAbles_, [](const std::weak_ptr<ClickAble>& a, const std::weak_ptr<ClickAble>& b)
    {
        return a.lock()->drawAble()->z() > b.lock()->drawAble()->z();
    });
}
