//
// Created by eal on 10/30/24.
//

#include "RayLibImplementation.h"
#include <thread>
#include "UpdateController.h"
#include "EngineBase/EngineBase.h"

RayLibImplementation::RayLibImplementation()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1200, 800, "M3");
    RayLibImplementation::loadTexture("../Textures/MissingTexture.png");
}

std::pair<int, int> RayLibImplementation::getMousePos()
{
    return {GetMouseX(), GetMouseY()};
}

void RayLibImplementation::draw(const std::vector<std::unique_ptr<DrawAble>>& drawAbles, int offsetX, int offsetY,
                                double updatesLastSecond)
{
    BeginDrawing();
    ClearBackground(BLACK);
    for (const auto& drawAble : drawAbles)
    {
        if (drawAble == nullptr || drawAble->getTextureLocation() == nullptr)
        {
            continue;
        }
        const std::string* texturePath = drawAble->getTextureLocation();
        if (not textureMap_.contains(*texturePath))
        {
            loadTexture(*texturePath);
        }
        auto texture = textureMap_[*texturePath];
        if (texture.id == 0)
        {
            texture = textureMap_["../Textures/MissingTexture.png"];
        }
        (texture).height = drawAble->getHeight();
        (texture).width = drawAble->getWidth();
        int drawX = drawAble->getX();
        int drawY = drawAble->getY();
        if (drawAble->getPositionIsAffectedByOffset())
        {
            drawX += offsetX;
            drawY += offsetY;
        }
        DrawTexture(texture, drawX, drawY, Color(255, 255, 255, 255));
    }
    DrawFPS(0, 0);
    DrawText(TextFormat("%.2f", updatesLastSecond), 0, 50, 24, GREEN);
    EndDrawing();
}

void RayLibImplementation::loadTexture(const std::string& texturePath)
{
    textureMap_.emplace(texturePath, LoadTexture(texturePath.c_str()));
}

std::pair<int, int> RayLibImplementation::getWindowSize()
{
    return {GetScreenWidth(), GetScreenHeight()};
}

bool RayLibImplementation::toCloseWindow()
{
    return WindowShouldClose();
}

void RayLibImplementation::closeWindow()
{
    CloseWindow();
}

bool RayLibImplementation::isKeyPressed(const Key key)
{
    return IsKeyPressed(key);
}

bool RayLibImplementation::isKeyDown(const Key key)
{
    return IsKeyDown(key);
}

bool RayLibImplementation::isKeyReleased(Key key)
{
    return IsKeyReleased(key);
}

bool RayLibImplementation::isMouseButtonDown(const Button button)
{
    return IsMouseButtonDown(button);
}

bool RayLibImplementation::isMouseButtonReleased(const Button button)
{
    return IsMouseButtonReleased(button);
}

bool RayLibImplementation::isMouseButtonPressed(const Button button)
{
    return IsMouseButtonPressed(button);
}

void RayLibImplementation::setTargetFPS(int targetFPS)
{
    SetTargetFPS(targetFPS);
}
