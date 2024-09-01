//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include "EngineBase.h"

#include "Controllers/ObjectController.h"
#include "Controllers/TextureController.h"

int EngineBase::loadTexture(const std::string& path)
{
    if (!windowInitialized_)
    {
        InitWindow(1200, 800, "M3");
        windowInitialized_ = true;
    }
    return TextureController::loadTexture(path);
}

void EngineBase::startGUI()
{
    while (!WindowShouldClose())
    {
        ObjectController::update();
    }
}
