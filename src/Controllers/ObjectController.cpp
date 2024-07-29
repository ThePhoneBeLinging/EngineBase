//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "ObjectController.h"

#include <algorithm>
#include <iostream>

std::vector<std::list<DrawAbleObject*>> ObjectController::mAllDrawables;

std::list<DrawAbleObject*> ObjectController::mToBeDeleted;

DrawAbleObject* ObjectController::mDraggedDrawAble;
SceneManager ObjectController::mSceneManager = SceneManager();

void ObjectController::addDrawAbleObject(DrawAbleObject* drawAble)
{
    while (drawAble->mSceneManager.getScene() >= mAllDrawables.capacity())
    {
        mAllDrawables.resize(mAllDrawables.size() + 1);
    }
    mAllDrawables[drawAble->mSceneManager.getScene()].push_back(drawAble);
    sortScene(drawAble->mSceneManager.getScene());
}

void ObjectController::removeObject(DrawAbleObject* drawAble)
{
    mToBeDeleted.push_back(drawAble);
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
    auto localDrawAbles = mAllDrawables;
    BeginDrawing();
    ClearBackground(WHITE);
    int scene = mSceneManager.getScene();
    for (auto drawAble : localDrawAbles[scene])
    {
        drawAble->draw();
    }

    EndDrawing();
}

void ObjectController::handleClicks()
{
    int x = GetMouseX();
    int y = GetMouseY();
    auto drawAbleList = mAllDrawables[mSceneManager.getScene()];


    for (auto drawAble = drawAbleList.rbegin(); drawAble != drawAbleList.rend(); ++drawAble)
    {
        DrawAbleObject* drawAbleObject = *drawAble;
        if (drawAbleObject->isPointInside(x, y))
        {
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                if (mDraggedDrawAble == nullptr)
                {
                    drawAbleObject->mButton.onClick();
                }
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                if (drawAbleObject->mDragAble.isDragable())
                {
                    mDraggedDrawAble = drawAbleObject;
                    drawAbleObject->mDragAble.startDrag(drawAbleObject, x, y);
                }
            }
            break;
        }
    }
    if (mDraggedDrawAble != nullptr)
    {
        mDraggedDrawAble->mDragAble.updateDragPos(mDraggedDrawAble, x, y);
        if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            mDraggedDrawAble->mDragAble.stopDrag();
            mDraggedDrawAble = nullptr;
        }
    }
}

void ObjectController::handleDeletions()
{
    std::list<DrawAbleObject*> toDelete = mToBeDeleted;
    for (auto drawAble : toDelete)
    {
        mAllDrawables[drawAble->mSceneManager.getScene()].remove(drawAble);
    }
    mToBeDeleted.clear();
}

void ObjectController::sortScene(int scene)
{
    //TODO Currently sorts everything again upon any change to z value of any object.
    // TLDR ineffecient
    if (mAllDrawables.capacity() != 0 && mAllDrawables[scene].size() >= 2)
    {
        mAllDrawables[scene].sort([](const DrawAbleObject* a, const DrawAbleObject* b)
        {
            return a->getZ() < b->getZ();
        });
    }
}
