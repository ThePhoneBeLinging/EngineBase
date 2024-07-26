//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "ObjectController.h"

#include <algorithm>

std::vector<std::list<DrawAbleObject*>> ObjectController::mAllDrawables;

std::list<DrawAbleObject*> ObjectController::mToBeDeleted;
std::vector<std::list<Button*>> ObjectController::mButtons;
std::list<Button*> ObjectController::mButtonsToBeDeleted;
int ObjectController::mScene = 0;

void ObjectController::addDrawAbleObject(DrawAbleObject* drawAble)
{
    while (drawAble->getScene() >= mAllDrawables.capacity())
    {
        mAllDrawables.resize(mAllDrawables.size() + 1);
    }
    mAllDrawables[drawAble->getScene()].push_back(drawAble);
    sortScene(drawAble->getScene());
}

void ObjectController::removeObject(DrawAbleObject* drawAble)
{
    mToBeDeleted.push_back(drawAble);
}

void ObjectController::removeButton(Button* button)
{
    mButtonsToBeDeleted.push_back(button);
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
    auto localDrawAbles = mAllDrawables;
    BeginDrawing();
    ClearBackground(WHITE);
    int scene = mScene;
    for (auto drawAble : localDrawAbles[scene])
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
        std::list<Button*> buttonList = mButtons[mScene];
        for (auto button = buttonList.rbegin(); button != buttonList.rend(); ++button)
        {
            Button* btn = *button;
            if (btn->isVisible() && btn->isPointInside(x, y))
            {
                btn->onClick();
                break;
            }
        }
    }
}

void ObjectController::handleDeletions()
{
    std::list<DrawAbleObject*> toDelete = mToBeDeleted;
    std::list<Button*> buttonsToDelete = mButtonsToBeDeleted;
    for (auto drawAble : toDelete)
    {
        mAllDrawables[drawAble->getScene()].remove(drawAble);
    }
    for (auto button : buttonsToDelete)
    {
        mButtons[button->getScene()].remove(button);
    }
    mToBeDeleted.clear();
    mButtonsToBeDeleted.clear();
}

void ObjectController::sortScene(int scene)
{
    //TODO Currently sorts everything again upon any change to z value of any object.
    // TLDR ineffecient
    mAllDrawables[scene].sort([](const DrawAbleObject* a, const DrawAbleObject* b)
    {
        return a->getZ() < b->getZ();
    });
    mButtons[scene].sort([](const Button* a, const Button* b)
    {
        return a->getZ() < b->getZ();
    });
}
