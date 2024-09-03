//
// Created by Elias Aggergaard Larsen on 01/09/2024.
//

#include "TextureController.h"

int TextureController::loadTexture(const std::string& path)
{
    auto texture = std::make_shared<Texture2D>(LoadTexture(path.c_str()));
    textures_.push_back(texture);
    return (int)textures_.size() - 1;
}

void TextureController::drawTexture(DrawAble* object)
{
    auto texture = textures_[textures_.size() - object->textureIndex() - 1];
    Texture2D copiedTexture = *texture;
    copiedTexture.height = object->height();
    copiedTexture.width = object->width();
    DrawTexture(copiedTexture, (int)object->x(), (int)object->y(), WHITE);
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
