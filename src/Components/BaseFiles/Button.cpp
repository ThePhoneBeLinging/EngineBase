//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "Button.h"

#include <ObjectController.h>

#include <utility>

Button::Button(int x, int y, int height, int width) : DrawAbleObject(
    x, y, height, width)
{
}

void Button::onClick()
{
    if (mFunction != nullptr && this->mVisibility.isVisisble())
    {
        mFunction(this);
    }
}

void Button::deleteObject()
{
    DrawAbleObject::deleteObject();
    ObjectController::removeButton(this);
}

void Button::setOnClick(std::function<void(Button*)> function)
{
    this->mFunction = std::move(function);
}

void Button::addToScene(int scene)
{
    this->mSceneManager.setScene(scene);
    ObjectController::addButton(this);
    DrawAbleObject::addToScene(scene);
}
