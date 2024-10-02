//
// Created by Elias Aggergaard Larsen on 05/09/2024.
//

#include "ClickAble.h"
#include <utility>

#include "Controllers/ObjectController.h"

ClickAble::ClickAble(int drawAbleID)
{
    drawAbleID_ = drawAbleID;
}

void ClickAble::setOnClick(std::function<void()> function)
{
    onClickFunction_ = std::move(function);
}

void ClickAble::onClick()
{
    onClickFunction_();
}

int ClickAble::drawAble()
{
    return drawAbleID_;
}
