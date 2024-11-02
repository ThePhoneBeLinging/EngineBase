//
// Created by eal on 10/30/24.
//

#include "RayLibImplementation.h"

#include <thread>

#include "DrawAbleObjects.h"
#include "UpdateController.h"
#include "EngineBase/EngineBase.h"

void RayLibImplementation::init()
{
    InitWindow(1200, 800, "M3");
}

void RayLibImplementation::drawFunction()
{
    while (not EngineBase::getGraphicsLibrary()->toCloseWindow())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        for (const auto& drawAble : DrawAbleObjects::getActiveDrawAbles())
        {
            EngineBase::getGraphicsLibrary()->draw(drawAble);
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
    std::unique_ptr<Texture2D>* texture = &textures[drawAble->getTextureIndex()];
    (*texture)->height = drawAble->getHeight();
    (*texture)->width = drawAble->getWidth();
    DrawTexture(**texture, drawAble->getX(), drawAble->getY(), Color(255, 255, 255,255));
}

int RayLibImplementation::loadTexture(const std::string& texturePath)
{
    textures.push_back(std::make_unique<Texture2D>(LoadTexture(texturePath.c_str())));
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

void RayLibImplementation::startWindow()
{
    std::thread thread(UpdateController::beginUpdateLoop);
    drawFunction();
    thread.join();
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
