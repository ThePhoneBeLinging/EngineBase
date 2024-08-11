//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "ObjectController.h"
#include "HotKeyManager.h"
#include <algorithm>
#include <iostream>

std::vector<std::list<DrawAbleObject*>> ObjectController::mAllDrawables;

std::list<DrawAbleObject*> ObjectController::mToBeDeleted;

DrawAbleObject* ObjectController::mDraggedDrawAble;
SceneManager ObjectController::mSceneManager = SceneManager();
std::mutex ObjectController::mMutex;

void ObjectController::addDrawAbleObject(DrawAbleObject* drawAble)
{
    mMutex.lock();
    while (drawAble->mSceneManager.getScene() >= mAllDrawables.capacity())
    {
        mAllDrawables.resize(mAllDrawables.size() + 1);
    }
    mAllDrawables[drawAble->mSceneManager.getScene()].push_back(drawAble);
    mMutex.unlock();
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
        HotKeyManager::handleHotKeys();
        drawAllObjects();
    }
}

void ObjectController::drawAllObjects()
{
    std::lock_guard<std::mutex> lock(mMutex);
    auto localDrawAbles = mAllDrawables;
    BeginDrawing();
    ClearBackground(WHITE);
    if (mSceneManager.getScene() >= mAllDrawables.size())
    {
        EndDrawing();
        return;
    }
    int scene = mSceneManager.getScene();
    for (auto drawAble : localDrawAbles[scene])
    {
        drawAble->draw();
    }

    EndDrawing();
}

void ObjectController::handleClicks()
{
    std::lock_guard<std::mutex> lock(mMutex);
    int x = GetMouseX();
    int y = GetMouseY();
    if (mSceneManager.getScene() >= mAllDrawables.size())
    {
        return;
    }
    auto drawAbleList = mAllDrawables[mSceneManager.getScene()];
    if (mDraggedDrawAble != nullptr)
    {
        SetMouseCursor(MOUSE_CURSOR_RESIZE_ALL);
    }
    else
    {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }

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
                    mDraggedDrawAble->mDragAble.startDrag(mDraggedDrawAble, x, y);
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
    std::lock_guard<std::mutex> lock(mMutex);
    std::list<DrawAbleObject*> toDelete = mToBeDeleted;
    for (auto drawAble : toDelete)
    {
        mAllDrawables[drawAble->mSceneManager.getScene()].remove(drawAble);
    }
    mToBeDeleted.clear();
}

void ObjectController::sortScene(int scene)
{
    std::lock_guard<std::mutex> lock(mMutex);
    //TODO Currently sorts everything again upon any change to z value of any object.
    // TLDR ineffecient
    if (mAllDrawables.capacity() != 0 && mAllDrawables[scene].size() >= 2)
    {
        mAllDrawables[scene].sort([](const DrawAbleObject* a, const DrawAbleObject* b)
        {
            return a->mTextureManager.getZ() < b->mTextureManager.getZ();
        });
    }
}

bool ObjectController::isKeyPressed(int key)
{
    return IsKeyPressed(key);
}

bool ObjectController::isKeyDown(int key)
{
    return IsKeyDown(key);
}

bool ObjectController::isKeyUp(int key)
{
    return IsKeyUp(key);
}

bool ObjectController::isKeyReleased(int key)
{
    return IsKeyReleased(key);
}
