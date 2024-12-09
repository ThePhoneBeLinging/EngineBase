//
// Created by eal on 10/30/24.
//

#include "RayLibImplementation.h"
#include <thread>
#include "UpdateController.h"
#include "EngineBase/EngineBase.h"

RayLibImplementation::RayLibImplementation()
{
    InitWindow(1200, 800, "M3");
    RayLibImplementation::loadTexture("../Textures/MissingTexture.png");
}

std::pair<int, int> RayLibImplementation::getMousePos()
{
    return {GetMouseX(), GetMouseY()};
}

void RayLibImplementation::draw(const std::vector<std::unique_ptr<DrawAble>> &drawAbles, int offsetX, int offsetY)
{
    BeginDrawing();
    ClearBackground(BLACK);
    for (const auto &drawAble: drawAbles)
    {
        if (drawAble == nullptr)
        {
            continue;
        }
        if (not textureMap_.contains(drawAble->getTextureLocation()))
        {
            loadTexture(drawAble->getTextureLocation());
        }
        auto texture = textureMap_[drawAble->getTextureLocation()];
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
    EndDrawing();
}

void RayLibImplementation::loadTexture(const std::string &texturePath)
{
    textureMap_.emplace(texturePath, LoadTexture(texturePath.c_str()));
}

std::pair<int, int> RayLibImplementation::getWindowSize()
{
    //TODO Actually do smth here, currently hardcoded because of init()
    return {1200, 800};
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
