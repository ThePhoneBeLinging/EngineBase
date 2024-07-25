//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//


#include "TextureController.h"

#include <iostream>

TextureController::TextureController()
{
    InitWindow(800,600,"M3");
    this->mTextures.resize(spacesPerResize);
}
//TODO Check this function, something seems off with the increments in size;
void TextureController::addTexture(Texture2D texture, int firstIndex, int secondIndex)
{
    while (mTextures.capacity() <= firstIndex)
    {
        mTextures.resize(mTextures.capacity() + spacesPerResize);
    }

    while (mTextures[firstIndex].capacity() <= secondIndex)
    {
        mTextures[firstIndex].resize(mTextures.capacity() + spacesPerResize);
    }
    this->mTextures[firstIndex][secondIndex] = texture;
}

Texture2D TextureController::getTexture(int firstIndex, int secondIndex)
{
    return this->mTextures[firstIndex][secondIndex];
}
