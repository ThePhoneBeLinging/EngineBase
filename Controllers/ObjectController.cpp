//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "ObjectController.h"

std::vector<std::list<DrawAbleObject*>> ObjectController::mDrawAbles;
std::list<DrawAbleObject*> ObjectController::toBeDeleted;
std::vector<std::list<Button*>> ObjectController::mButtons;
std::list<Button*> ObjectController::buttonsToBeDeleted;
int ObjectController::mScene = 0;

void ObjectController::addDrawAbleObject(DrawAbleObject* drawAble)
{
    while (drawAble->getScene() >= mDrawAbles.capacity())
    {
        mDrawAbles.resize(mDrawAbles.capacity() + 2);
    }
    mDrawAbles[drawAble->getScene()].push_back(drawAble);
}

void ObjectController::removeObject(DrawAbleObject* drawAble)
{
    toBeDeleted.push_back(drawAble);
}

void ObjectController::removeButton(Button* button)
{
    buttonsToBeDeleted.push_back(button);
}

void ObjectController::addButton(Button* button)
{
    while (button->getScene() >= mButtons.capacity())
    {
        mButtons.resize(mButtons.capacity() + 2);
    }
    mButtons[button->getScene()].push_back(button);
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

void ObjectController::setScene(int scene)
{
    mScene = scene;
}

int ObjectController::getScene()
{
    return mScene;
}

void ObjectController::drawAllObjects()
{
    auto localDrawAbles = mDrawAbles;
    BeginDrawing();
    ClearBackground(WHITE);

    for (auto drawAble : localDrawAbles[mScene])
    {
        if (drawAble->isVisible())
        {
            drawAble->draw();
        }
    }

    EndDrawing();
}

void ObjectController::handleClicks()
{
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        int x = GetMouseX();
        int y = GetMouseY();
        std::vector<std::list<Button*>> buttonList = mButtons;
        for (auto button : buttonList[mScene])
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
        mDrawAbles[drawAble->getScene()].remove(drawAble);
    }
    for (auto button : buttonsToDelete)
    {
        mButtons[button->getScene()].remove(button);
    }
}
