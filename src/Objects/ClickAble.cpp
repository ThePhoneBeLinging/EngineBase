//
// Created by Elias Aggergaard Larsen on 05/09/2024.
//

#include "EngineBase/ClickAble.h"
#include <utility>

ClickAble::ClickAble(DrawAble* drawAble)
{
    drawAble_ = drawAble;
}

void ClickAble::setOnClick(std::function<void(DrawAble*)> function)
{
    onClickFunction_ = std::move(function);
}

void ClickAble::onClick()
{
    onClickFunction_(drawAble_);
}
