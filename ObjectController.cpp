//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "ObjectController.h"

#include <iostream>

std::list<DrawAbleObject*> ObjectController::drawAbles;

void ObjectController::addDrawAbleObject(DrawAbleObject* drawAble)
{
    drawAbles.push_back(drawAble);
}

void ObjectController::keepDrawingObjects()
{
    while (!WindowShouldClose())
    {
        drawAllObjects();
    }
}

void ObjectController::drawAllObjects()
{
    auto localDrawAbles = drawAbles;
    BeginDrawing();
    ClearBackground(WHITE);
    for (auto drawAble : localDrawAbles)
    {
        drawAble->draw();
    }
    EndDrawing();
}
