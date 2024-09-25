//
// Created by Elias Aggergaard Larsen on 01/09/2024.
//

#include "TextureController.h"

int TextureController::loadTexture(const std::string &path)
{
    auto texture = std::make_shared<Texture2D>(LoadTexture(path.c_str()));
    if (texture->id == 0)
    {
        auto newPath = "../" + path;
        texture = std::make_shared<Texture2D>(LoadTexture(newPath.c_str()));
    }
    textures_.push_back(texture);
    return (int) textures_.size() - 1;
}

void TextureController::drawTexture(float x, float y, int width, int height, int textureIndex)
{
    auto texture = textures_[textureIndex];
    Texture2D copiedTexture = *texture;
    copiedTexture.height = height;
    copiedTexture.width = width;
    DrawTexture(copiedTexture, (int) x, (int) y, WHITE);
}

void TextureController::initializeWindow()
{
    InitWindow(1200, 800, "M3");
    loadTexture("Textures/MissingTexture.png");
}

void TextureController::startDrawing()
{
    BeginDrawing();
    ClearBackground(BLACK);
}

void TextureController::endDrawing()
{
    EndDrawing();
}
