//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include <algorithm>
#include "ObjectController.h"
#include "TextureController.h"

void ObjectController::update(float deltaTime)
{
    drawObjects();
    handleClicks();
    updateSpeedAbles(deltaTime);
}

void ObjectController::addDrawAble(DrawAble* drawAble)
{
    drawAbles_.push_back(drawAble);
    sortDrawAbles();
}

void ObjectController::removeDrawAble(DrawAble* drawAble)
{
    drawAbles_.erase(std::ranges::remove(drawAbles_, drawAble).begin(), drawAbles_.end());
}

void ObjectController::addDragAble(DragAble* dragAble)
{
    dragAbles_.push_back(dragAble);
    sortDragAbles();
}

void ObjectController::removeDragAble(DragAble* dragAble)
{
    dragAbles_.erase(std::ranges::remove(dragAbles_, dragAble).begin(), dragAbles_.end());
}

void ObjectController::addSpeedAble(SpeedAble* speedAble)
{
    speedAbles_.push_back(speedAble);
}

void ObjectController::removeSpeedAble(SpeedAble* speedAble)
{
    speedAbles_.erase(std::ranges::remove(speedAbles_, speedAble).begin(), speedAbles_.end());
}

void ObjectController::addClickAble(ClickAble* clickAble)
{
    clickAbles_.push_back(clickAble);
}

void ObjectController::removeClickAble(ClickAble* clickAble)
{
    clickAbles_.erase(std::ranges::remove(clickAbles_, clickAble).begin(), clickAbles_.end());
}

void ObjectController::drawObjects()
{
    TextureController::startDrawing();
    for (const auto& drawAble : drawAbles_)
    {
        drawAble->draw();
    }
    TextureController::endDrawing();
}

void ObjectController::handleClicks()
{
    auto mousePos = GetMousePosition();
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        if (currentDragged_ != nullptr)
        {
            currentDragged_->updateDrag(mousePos.x, mousePos.y);
        }
        else
        {
            for (const auto& dragAble : dragAbles_)
            {
                if (dragAble->getDrawAble()->isPointInside(mousePos.x, mousePos.y))
                {
                    dragAble->startDrag(mousePos.x, mousePos.y);
                    currentDragged_ = dragAble;
                    break;
                }
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
        speedAble->update(deltaTime);
    }
}

void ObjectController::sortDrawAbles()
{
    std::ranges::sort(drawAbles_, [](DrawAble* a, DrawAble* b) { return a->z() <= b->z(); });
}

void ObjectController::sortDragAbles()
{
    std::ranges::sort(
        dragAbles_, [](DragAble* a, DragAble* b) { return a->getDrawAble()->z() > b->getDrawAble()->z(); });
}
