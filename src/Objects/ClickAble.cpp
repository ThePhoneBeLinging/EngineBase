//
// Created by Elias Aggergaard Larsen on 05/09/2024.
//

#include "EngineBase/ClickAble.h"
#include <utility>

#include "Controllers/ObjectController.h"

ClickAble::ClickAble(DrawAble* drawAble)
{
    drawAble_ = drawAble;
    ObjectController::addClickAble(this);
}

void ClickAble::setOnClick(std::function<void()> function)
{
    onClickFunction_ = std::move(function);
}

void ClickAble::onClick()
{
    onClickFunction_();
}

DrawAble* ClickAble::drawAble()
{
    return drawAble_;
}
