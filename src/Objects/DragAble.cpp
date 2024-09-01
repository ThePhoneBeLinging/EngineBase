//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include "DragAble.h"

DragAble::DragAble(DrawAble* drawAble) : drawAble_(drawAble), oldX_(0), oldY_(0)
{
}

void DragAble::startDrag()
{
    this->oldX_ = this->drawAble_->x();
    this->oldY_ = this->drawAble_->y();
}

void DragAble::cancelDrag()
{
    this->drawAble_->x(oldX_);
    this->drawAble_->y(oldY_);
}

void DragAble::updateDrag(float x, float y)
{
    this->drawAble_->x(x);
    this->drawAble_->y(y);
}
