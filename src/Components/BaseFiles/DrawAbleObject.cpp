//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "DrawAbleObject.h"

#include "ObjectController.h"
#include "TextureController.h"

DrawAbleObject::DrawAbleObject(int x, int y, int height, int width,
                               const std::shared_ptr<TextureController>& textureController)
{
    this->x = x;
    this->y = y;
    this->z = 0;
    this->mTextureIndex = 0;
    this->mTextureSecondIndex = 0;
    this->mHeight = height;
    this->mWidth = width;
    this->mIsVisible = true;
    this->mIsDragAble = true;
    this->mTextureController = textureController;
    this->mScene = 0;
}

void DrawAbleObject::draw()
{
    if (this->mIsVisible)
    {
        Texture2D textureToDraw = mTextureController->getTexture(this->mTextureIndex, this->mTextureSecondIndex);
        textureToDraw.width = mWidth;
        textureToDraw.height = mHeight;
        DrawTexture(textureToDraw, this->x, this->y,
                    WHITE);
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

void DrawAbleObject::setX(int x)
{
    this->x = x;
}

void DrawAbleObject::setY(int y)
{
    this->y = y;
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

void DrawAbleObject::setHeight(int height)
{
    this->mHeight = height;
}

void DrawAbleObject::setWidth(int width)
{
    this->mWidth = width;
}

void DrawAbleObject::setVisible(bool isVisible)
{
    this->mIsVisible = isVisible;
}

int DrawAbleObject::getX() const
{
    return x;
}

int DrawAbleObject::getY() const
{
    return y;
}

int DrawAbleObject::getTextureIndex() const
{
    return mTextureIndex;
}

int DrawAbleObject::getSecondTextureIndex() const
{
    return mTextureSecondIndex;
}

int DrawAbleObject::getHeight() const
{
    return mHeight;
}

int DrawAbleObject::getWidth() const
{
    return mWidth;
}

bool DrawAbleObject::isVisible() const
{
    return mIsVisible;
}

int DrawAbleObject::getScene() const
{
    return mScene;
}

void DrawAbleObject::setScene(int scene)
{
    this->mScene = scene;
}

bool DrawAbleObject::isDragAble() const
{
    return this->mIsDragAble;
}

void DrawAbleObject::setDragAble(bool dragAble)
{
    this->mIsDragAble = dragAble;
}




