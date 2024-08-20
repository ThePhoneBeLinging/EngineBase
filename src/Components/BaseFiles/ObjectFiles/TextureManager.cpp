//
// Created by Elias Aggergaard Larsen on 29/07/2024.
//

#include <cassert>
#include "TextureManager.h"

#include "Controllers/ObjectController.h"

TextureManager::TextureManager(DrawAbleObject *drawAble)
{
    this->mDrawAble = drawAble;
}

void TextureManager::advanceAnimation()
{
    this->mCurrentFrames++;
    if (this->mTextureSecondIndex == this->mAnimationFinalIndex)
    {
        this->mTextureSecondIndex -= this->mFramesShown;
        this->mFramesShown = 0;
    }
    else if (mCurrentFrames == mFramesPerAnimationFrame)
    {
        this->mCurrentFrames = 0;
        this->mFramesShown++;
        this->mTextureSecondIndex++;
    }
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
    assert(textureIndex >= 0);
    this->mTextureIndex = textureIndex;
}

void TextureManager::setTextureSecondIndex(int secondIndex)
{
    assert(secondIndex >= 0);
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

void TextureManager::setFramesPerAnimationFrame(int framesPerUpdate)
{
    assert(framesPerUpdate >= 0);
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


