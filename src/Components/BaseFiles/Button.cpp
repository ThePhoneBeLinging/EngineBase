//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "Button.h"
#include <utility>

void Button::onClick()
{
    if (mFunction != nullptr)
    {
        mFunction(this);
    }
}

void Button::setOnClick(std::function<void(Button*)> function)
{
    this->mFunction = std::move(function);
}
