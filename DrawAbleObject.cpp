//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "DrawAbleObject.h"

DrawAbleObject::DrawAbleObject(int textureIndex, int height, int width)
{
    this->mTextureIndex = textureIndex;
    this->mTextureState = 0;
    this->mHeight = height;
    this->mWidth = width;
    this->mIsVisible = true;
}

void DrawAbleObject::draw()
{
}
