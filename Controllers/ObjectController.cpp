//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "ObjectController.h"

std::list<DrawAbleObject*> ObjectController::drawAbles;
std::list<DrawAbleObject*> ObjectController::toBeDeleted;
std::list<Button*> ObjectController::buttons;
std::list<Button*> ObjectController::buttonsToBeDeleted;

void ObjectController::addDrawAbleObject(DrawAbleObject* drawAble)
{
    drawAbles.push_back(drawAble);
}

void ObjectController::removeObject(DrawAbleObject* drawAble)
{
    ObjectController::toBeDeleted.push_back(drawAble);
}

void ObjectController::removeButton(Button* button)
{
    buttonsToBeDeleted.push_back(button);
}

void ObjectController::addButton(Button* button)
{
    buttons.push_back(button);
}

void ObjectController::keepDrawingObjects()
{
    while (!WindowShouldClose())
    {
        handleDeletions();
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
        std::list<Button*> buttonList = buttons;
        for (auto button : buttonList)
        {
            if (button->isVisible() && button->isPointInside(x, y))
            {
                button->onClick();
            }
        }
    }
}

void ObjectController::handleDeletions()
{
    std::list<DrawAbleObject*> toDelete = toBeDeleted;
    std::list<Button*> buttonsToDelete = buttonsToBeDeleted;
    for (auto drawAble : toDelete)
    {
        drawAbles.remove(drawAble);
    }
    for (auto button : buttonsToDelete)
    {
        buttons.remove(button);
    }
}
