//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include "DragAble.h"

#include "Controllers/ObjectController.h"

DragAble::DragAble(DrawAble *drawAble) : drawAble_(drawAble), oldX_(0), oldY_(0), offsetX_(0), offsetY_(0)
{
}

DragAble::~DragAble()
{
}

void DragAble::startDrag(float x, float y)
{
    this->offsetX_ = this->drawAble_->x() - x;
    this->offsetY_ = this->drawAble_->y() - y;
    updateDrag(x, y);
}

void DragAble::cancelDrag()
{
    this->drawAble_->x(oldX_);
    this->drawAble_->y(oldY_);
}

void DragAble::updateDrag(float x, float y)
{
    this->drawAble_->x(x + offsetX_);
    this->drawAble_->y(y + offsetY_);
}

DrawAble *DragAble::getDrawAble()
{
    return drawAble_;
}
