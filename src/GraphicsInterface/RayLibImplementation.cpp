//
// Created by eal on 10/30/24.
//

#include "RayLibImplementation.h"

#include <thread>

#include "DrawAbleObjects.h"

void RayLibImplementation::init()
{
    InitWindow(1200, 800, "M3");
    std::thread (drawFunction);
    textures.resize(1024);
}

void RayLibImplementation::drawFunction()
{
    while (not toCloseWindow())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        for (const auto& drawAble : DrawAbleObjects::getActiveDrawAbles())
        {
            draw(drawAble);
        }
        EndDrawing();
    }
}

std::pair<int, int> RayLibImplementation::getMousePos()
{
    return {GetMouseX(), GetMouseY()};
}

void RayLibImplementation::draw(const std::shared_ptr<DrawAble> drawAble)
{
    Texture2D texture = textures[drawAble->getTextureIndex()];
    texture.height = drawAble->getHeight();
    texture.width = drawAble->getWidth();

    DrawTexture(texture, drawAble->getX(), drawAble->getY(), Color(0, 0, 0));
}

int RayLibImplementation::loadTexture(const std::string& texturePath)
{
    textures.push_back(LoadTexture(texturePath.c_str()));
    return static_cast<int>(textures.size()) - 1;
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
