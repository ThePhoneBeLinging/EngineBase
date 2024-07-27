//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//


#include "TextureController.h"


#include "ObjectController.h"

TextureController::TextureController()
{
    InitWindow(800, 600, "M3");
    this->mTextures.resize(spacesPerResize);
}

//TODO Check this function, something seems off with the increments in size;
void TextureController::addTexture(const std::string& texturePath, int firstIndex, int secondIndex)
{
    Texture2D texture = LoadTexture(texturePath.c_str());
    while (mTextures.capacity() <= firstIndex)
    {
        mTextures.resize(mTextures.capacity() + spacesPerResize);
    }

    while (mTextures[firstIndex].capacity() <= secondIndex)
    {
        mTextures[firstIndex].resize(mTextures[firstIndex].capacity() + spacesPerResize);
    }
    this->mTextures[firstIndex][secondIndex] = texture;
}

void TextureController::draw(int x, int y, int height, int width, int firstIndex, int secondIndex)
{
    Texture2D texture = mTextures[firstIndex][secondIndex];
    texture.height = height;
    texture.width = width;
    DrawTexture(texture, x, y,WHITE);
}