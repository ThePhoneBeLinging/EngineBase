//
// Created by Elias Aggergaard Larsen on 29/07/2024.
//

#include "TextureManager.h"

#include "Controllers/ObjectController.h"

void TextureManager::advanceAnimation()
{
    if (this->mTextureSecondIndex == this->mAnimationFinalIndex)
    {
        this->mTextureSecondIndex -= this->mCurrentFrames;
        this->mCurrentFrames = 0;
    }
    this->mCurrentFrames++;
    this->mTextureSecondIndex++;
}

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

int TextureManager::getAnimationEndIndex() const
{
    return mAnimationFinalIndex;
}

void TextureManager::setAnimationEndIndex(int animationFinalIndex)
{
    this->mAnimationFinalIndex = animationFinalIndex;
}

int TextureManager::getFramesPerAnimationFrame() const
{
    return mFramesPerAnimationFrame;
}

void TextureManager::setFramePerAnimationFrame(int framesPerUpdate)
{
    this->mFramesPerAnimationFrame = framesPerUpdate;
}

int TextureManager::getCurrentFrames() const
{
    return mCurrentFrames;
}

void TextureManager::setCurrentFrames(int currentFrames)
{
    mCurrentFrames = currentFrames;
}
