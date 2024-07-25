//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//


#include "TextureController.h"

#include <iostream>

TextureController::TextureController()
{
    InitWindow(800,600,"M3");
    this->mTextures.resize(5);
}

void TextureController::addTexture(Texture2D texture, int firstIndex, int secondIndex)
{
    this->mTextures[firstIndex][secondIndex] = texture;
}

Texture2D TextureController::getTexture(int firstIndex, int secondIndex)
{
    return this->mTextures[firstIndex][secondIndex];
}
