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
    // Only to allow -werror
    deltaTime += deltaTime;
}

void ObjectController::addDrawAble(int id)
{
    std::lock_guard<std::mutex> lock(drawAblesMutex);
    drawAbles_.push_back(id);
}

void ObjectController::drawObjects()
{
    std::unique_lock<std::mutex> lock(drawAblesMutex);
    auto drawAbles = drawAbles_;
    lock.unlock();
    TextureController::startDrawing();
    for (const auto& drawAble : drawAbles_)
    {
        auto drawAblePtr = ObjectKeeper::getDrawAbleForReading(drawAble);
        if (drawAblePtr != nullptr)
        {
            drawAblePtr->draw();
        }
    }
    TextureController::endDrawing();
}

void ObjectController::sortDrawAbles()
{
    std::ranges::sort(drawAbles_, [](const int& a, const int& b)
    {
        auto aPtr = ObjectKeeper::getDrawAbleForReading(a);
        auto bPtr = ObjectKeeper::getDrawAbleForReading(b);
        return aPtr->z() < bPtr->z();
    });
}

void ObjectController::keepDrawing()
{
    while (!WindowShouldClose())
    {
        drawObjects();
    }
}

