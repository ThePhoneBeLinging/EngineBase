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
    while (mTextures.capacity() <= firstIndex)
    {
        mTextures.resize(mTextures.capacity() + spacesPerResize);
    }

    while (mTextures[firstIndex].capacity() <= secondIndex)
    {
        mTextures[firstIndex].resize(mTextures[firstIndex].capacity() + spacesPerResize);
    }
    if (texturePath == "BLACK")
    {
        Image image = GenImageColor(50, 50,BLACK);
        mTextures[firstIndex][secondIndex] = LoadTextureFromImage(image);
    }
    else if (texturePath == "WHITE")
    {
        Image image = GenImageColor(50, 50,WHITE);
        mTextures[firstIndex][secondIndex] = LoadTextureFromImage(image);
    }
    else
    {
        mTextures[firstIndex][secondIndex] = LoadTexture(texturePath.c_str());
    }
}

void TextureController::draw(int x, int y, int height, int width, int firstIndex, int secondIndex)
{
    Texture2D texture = mTextures[firstIndex][secondIndex];
    float scaleFactor = width * (GetScreenWidth() / 1000);
    DrawTexture(texture, x, y,WHITE);
    Vector2 pos = {(float)x, (float)y};
    DrawTextureEx(texture, pos, 0, scaleFactor,WHITE);
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
