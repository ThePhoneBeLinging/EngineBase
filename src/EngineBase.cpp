//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include "EngineBase.h"

#include "Controllers/ObjectController.h"
#include "Controllers/TextureController.h"

int EngineBase::loadTexture(const std::string& path)
{
    initializeWindow();
    return TextureController::loadTexture(path);
}

void EngineBase::startGUI(const std::function<void(float deltaTime)>& updateFunction)
{
    initializeWindow();
    while (!WindowShouldClose())
    {
        ObjectController::update();
        updateFunction(GetFrameTime());
    }
}

void EngineBase::initializeWindow()
{
    if (windowInitialized_) return;


    InitWindow(1200, 800, "M3");
    windowInitialized_ = true;
    TextureController::loadTexture("Textures/MissingTexture.png");
}
