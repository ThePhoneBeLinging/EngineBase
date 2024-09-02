//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include "ObjectController.h"
#include "raylib.h"

void ObjectController::update(float deltaTime)
{
    drawObjects();
    handleClicks();
    updateSpeedAbles(deltaTime);
}

void ObjectController::addDrawAble(DrawAble* drawAble)
{
    drawAbles_.push_back(drawAble);
}

void ObjectController::removeDrawAble(DrawAble* drawAble)
{
    drawAbles_.erase(std::ranges::remove(drawAbles_, drawAble).begin(), drawAbles_.end());
}

void ObjectController::addDragAble(DragAble* dragAble)
{
    dragAbles_.push_back(dragAble);
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

void ObjectController::drawObjects()
{
    BeginDrawing();
    ClearBackground(BLACK);
    for (const auto& drawAble : drawAbles_)
    {
        drawAble->draw();
    }
    EndDrawing();
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
