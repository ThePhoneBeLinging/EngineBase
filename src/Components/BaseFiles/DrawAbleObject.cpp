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
    this->z = 0;
    this->mTextureIndex = 0;
    this->mTextureSecondIndex = 0;
    this->mHeight = height;
    this->mWidth = width;
    this->mVisibility = Visibility();
    this->mDragAble = DragAble();
    this->mSceneManager = SceneManager();
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
                                    drawAble->mTextureIndex, drawAble->mTextureSecondIndex);
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


int DrawAbleObject::getZ() const
{
    return z;
}

void DrawAbleObject::setZ(int z)
{
    this->z = z;
    ObjectController::sortScene(this->mSceneManager.getScene());
}

void DrawAbleObject::setTextureIndex(int textureIndex)
{
    this->mTextureIndex = textureIndex;
}

void DrawAbleObject::setTextureSecondIndex(int secondIndex)
{
    this->mTextureSecondIndex = secondIndex;
}


int DrawAbleObject::getTextureIndex() const
{
    return mTextureIndex;
}

int DrawAbleObject::getSecondTextureIndex() const
{
    return mTextureSecondIndex;
}




