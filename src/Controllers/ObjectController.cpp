//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include "ObjectController.h"

#include "raylib.h"

void ObjectController::update()
{
    drawObjects();
}

void ObjectController::addDrawAble(DrawAble* drawAble)
{
    drawAbles_.push_back(drawAble);
}

void ObjectController::removeDrawAble(DrawAble* drawAble)
{
    drawAbles_.erase(std::ranges::remove(drawAbles_, drawAble).begin(), drawAbles_.end());
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
