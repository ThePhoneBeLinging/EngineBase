//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "DrawAbleObject.h"

#include "ObjectController.h"
#include "TextureController.h"

DrawAbleObject::DrawAbleObject(int x, int y, int height, int width) : Object(
    x, y, height, width)
{
    this->x = x;
    this->y = y;
    this->mHeight = height;
    this->mWidth = width;
    this->mTextureManager = TextureManager();
    this->mTextureManager.setDrawAble(this);
    this->mVisibility = Visibility();
    this->mDragAble = DragAble();
    this->mSceneManager = SceneManager();
    this->mButton = Button();
    this->mConnectionManager = ConnectionManager();
    mConnectionManager.connectDrawAble(this);
}

void DrawAbleObject::draw()
{
    for (auto drawAble : mConnectionManager.getConnectedObjects())
    {
        if (drawAble->mVisibility.isVisisble())
        {
            TextureController::draw(drawAble->x, drawAble->y, drawAble->mHeight, drawAble->mWidth,
                                    drawAble->mTextureManager.getTextureIndex(),
                                    drawAble->mTextureManager.getSecondTextureIndex());
        }
    }
}

void DrawAbleObject::deleteObject()
{
    ObjectController::removeObject(this);
}

void DrawAbleObject::addToScene(int scene)
{
    this->mSceneManager.setScene(scene);
    ObjectController::addDrawAbleObject(this);
}

void DrawAbleObject::removeFromScene()
{
    ObjectController::removeObject(this);
}






