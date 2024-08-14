//
// Created by Elias Aggergaard Larsen on 29/07/2024.
//

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H


class DrawAbleObject;

class TextureManager
{
public:
    TextureManager() = default;
    void advanceAnimation();
    void setDrawAble(DrawAbleObject* drawAble);
    int getZ() const;
    void setZ(int z);
    void setTextureIndex(int textureIndex);
    void setTextureSecondIndex(int secondIndex);
    int getTextureIndex() const;
    int getSecondTextureIndex() const;
    int getAnimationEndIndex() const;
    void setAnimationEndIndex(int animationFinalIndex);
    int getFramesPerAnimationFrame() const;
    void setFramesPerAnimationFrame(int framesPerUpdate);
    int getCurrentFrames() const;
    void setCurrentFrames(int currentFrames);

private:
    int z = 0;
    int mTextureIndex = 0;
    int mTextureSecondIndex = 0;
    int mAnimationFinalIndex = 0;
    int mFramesPerAnimationFrame = 0;
    int mCurrentFrames = 0;
    int mFramesShown = 0;
    DrawAbleObject* mDrawAble;
};


#endif //TEXTUREMANAGER_H
