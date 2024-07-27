//
// Created by Elias Aggergaard Larsen on 27/07/2024.
//

#include "EngineBase.h"

#include <ObjectController.h>

TextureController EngineBase::mTextureController = TextureController();

void EngineBase::addTexture(const std::string& texturePath, int firstIndex, int secondIndex)
{
    mTextureController.addTexture(texturePath, firstIndex, secondIndex);
}

void EngineBase::setScene(int scene)
{
    ObjectController::setScene(scene);
}

void EngineBase::startGUI()
{
    ObjectController::keepDrawingObjects();
}
