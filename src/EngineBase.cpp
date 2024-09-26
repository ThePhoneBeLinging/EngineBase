//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include <Controllers/ObjectKeeper.h>
#include "EngineBase/EngineBase.h"
#include "Controllers/ObjectController.h"
#include "Controllers/TextureController.h"

int EngineBase::loadTexture(const std::string &path)
{
    initializeWindow();
    return TextureController::loadTexture(path);
}

void EngineBase::startGUI(const std::function<void(float deltaTime)> &updateFunction)
{
    initializeWindow();
    while (!WindowShouldClose())
    {
        auto frameTime = GetFrameTime();
        ObjectController::update(frameTime);
        updateFunction(frameTime);
    }
}

bool EngineBase::keyPressed(Key key)
{
    return IsKeyDown(key);
}

bool EngineBase::keyReleased(Key key)
{
    return IsKeyReleased(key);
}

bool EngineBase::mouseButtonPressed(Button mouseButton)
{
    return IsMouseButtonDown(mouseButton);
}

bool EngineBase::mouseButtonReleased(Button mouseButton)
{
    return IsMouseButtonReleased(mouseButton);
}

int EngineBase::addDrawAble()
{
    auto drawAbleIndex = ObjectKeeper::addDrawAble();
    ObjectController::addDrawAble(drawAbleIndex);
    return drawAbleIndex;
}

int EngineBase::addSpeedAble()
{
    //ObjectController::addSpeedAble(speedAble);
    return 0;
}

int EngineBase::addDragAble()
{
    //ObjectController::addDragAble(dragAble);
    return 0;
}


void EngineBase::initializeWindow()
{
    if (windowInitialized_)
    { return; }

    InitWindow(1200, 800, "M3");
    windowInitialized_ = true;
    TextureController::loadTexture("Textures/MissingTexture.png");
}

void EngineBase::executeCommand(Command command)
{
    ObjectKeeper::executeCommand(command);
}
