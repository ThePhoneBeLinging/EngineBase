//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//


#include "TextureController.h"
#include "ObjectController.h"

std::vector<std::vector<Texture2D>> TextureController::mTextures;
int TextureController::spacesPerResize = 50;
bool TextureController::mWindowInitialized = false;

//TODO Check this function, something seems off with the increments in size;
void TextureController::addTexture(const std::string& texturePath, int firstIndex, int secondIndex)
{
    initWindow();
    Texture2D texture = LoadTexture(texturePath.c_str());
    while (mTextures.capacity() <= firstIndex)
    {
        mTextures.resize(mTextures.capacity() + spacesPerResize);
    }

    while (mTextures[firstIndex].capacity() <= secondIndex)
    {
        mTextures[firstIndex].resize(mTextures[firstIndex].capacity() + spacesPerResize);
    }
    mTextures[firstIndex][secondIndex] = texture;
}

void TextureController::draw(int x, int y, int height, int width, int firstIndex, int secondIndex)
{
    Texture2D texture = mTextures[firstIndex][secondIndex];
    texture.height = height;
    texture.width = width;
    DrawTexture(texture, x, y,WHITE);
}

void TextureController::initWindow()
{
    if (!mWindowInitialized)
    {
        int height = 600;
        int width = 800;
        std::string title = "M3";
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        InitWindow(width, height, title.c_str());
        mWindowInitialized = true;
    }
}
