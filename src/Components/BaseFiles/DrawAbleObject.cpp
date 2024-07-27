//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "DrawAbleObject.h"

#include "ObjectController.h"
#include "TextureController.h"

DrawAbleObject::DrawAbleObject(int x, int y, int height, int width,
                               const std::shared_ptr<TextureController>& textureController) : Object(
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
    this->mTextureController = textureController;
    this->mScene = 0;
}

void DrawAbleObject::draw()
{
    if (this->mVisibility.isVisisble())
    {
        mTextureController->draw(x, y, mHeight, mWidth, mTextureIndex, mTextureSecondIndex);
    }
}

void DrawAbleObject::deleteObject()
{
    ObjectController::removeObject(this);
}

void DrawAbleObject::addToScene(int scene)
{
    this->setScene(scene);
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
    ObjectController::sortScene(this->getScene());
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

int DrawAbleObject::getScene() const
{
    return mScene;
}

void DrawAbleObject::setScene(int scene)
{
    this->mScene = scene;
}




