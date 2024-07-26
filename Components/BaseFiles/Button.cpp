//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "Button.h"

#include <ObjectController.h>

#include <utility>

Button::Button(int x, int y, int height, int width,
               std::shared_ptr<TextureController>& textureController) : PointCheckerObject(
    x, y, height, width, textureController)
{
    ObjectController::addButton(this);
}

void Button::onClick()
{
    if (mFunction != nullptr)
    {
        mFunction();
    }
}

void Button::deleteObject()
{
    PointCheckerObject::deleteObject();
    ObjectController::removeButton(this);
}

void Button::setOnClick(std::function<void()> function)
{
    this->mFunction = std::move(function);
}
