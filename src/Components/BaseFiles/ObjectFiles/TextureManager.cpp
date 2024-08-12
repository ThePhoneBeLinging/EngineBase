//
// Created by Elias Aggergaard Larsen on 29/07/2024.
//

#include "TextureManager.h"

#include "Controllers/ObjectController.h"

void TextureManager::setDrawAble(DrawAbleObject* drawAble)
{
    this->mDrawAble = drawAble;
}

int TextureManager::getZ() const
{
    return z;
}

void TextureManager::setZ(int z)
{
    this->z = z;
    ObjectController::sortScene(mDrawAble->mSceneManager.getScene());
}

void TextureManager::setTextureIndex(int textureIndex)
{
    this->mTextureIndex = textureIndex;
}

void TextureManager::setTextureSecondIndex(int secondIndex)
{
    this->mTextureSecondIndex = secondIndex;
}


int TextureManager::getTextureIndex() const
{
    return mTextureIndex;
}

int TextureManager::getSecondTextureIndex() const
{
    return mTextureSecondIndex;
}
