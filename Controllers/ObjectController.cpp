//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "ObjectController.h"

std::list<DrawAbleObject*> ObjectController::drawAbles;
std::list<Button*> ObjectController::buttons;

void ObjectController::addDrawAbleObject(DrawAbleObject* drawAble)
{
    drawAbles.push_back(drawAble);
}

void ObjectController::addButton(Button* button)
{
    buttons.push_back(button);
}

void ObjectController::keepDrawingObjects()
{
    while (!WindowShouldClose())
    {
        handleClicks();
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

void ObjectController::handleClicks()
{
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        int x = GetMouseX();
        int y = GetMouseY();
        for (auto button : buttons)
        {
            button->onClick();
            if (button->isVisible() && button->isPointInside(x, y))
            {
                button->onClick();
            }
        }
    }
}
