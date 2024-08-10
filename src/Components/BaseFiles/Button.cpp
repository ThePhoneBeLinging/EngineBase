//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "Button.h"
#include <utility>


void Button::setDrawAbleObject(DrawAbleObject* drawAble)
{
    this->mDrawAble = drawAble;
}

void Button::onClick()
{
    if (mFunction != nullptr)
    {
        mFunction(this->mDrawAble);
    }
}

void Button::setOnClick(std::function<void(DrawAbleObject*)> function)
{
    this->mFunction = std::move(function);
}
