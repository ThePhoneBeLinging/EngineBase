//
// Created by Elias Aggergaard Larsen on 27/07/2024.
//

#include "EngineBase.h"

#include <ObjectController.h>

void EngineBase::addTexture(const std::string& texturePath, int firstIndex, int secondIndex)
{
    TextureController::addTexture(texturePath, firstIndex, secondIndex);
}

void EngineBase::setScene(int scene)
{
    ObjectController::mSceneManager.setScene(scene);
}

int EngineBase::getScene()
{
    return ObjectController::mSceneManager.getScene();
}

void EngineBase::startGUI()
{
    TextureController::initWindow();
    ObjectController::keepDrawingObjects();
}
