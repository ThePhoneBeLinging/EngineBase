//
// Created by Elias Aggergaard Larsen on 27/07/2024.
//

#include "DragAble.h"

#include <DrawAbleObject.h>

void DragAble::setDragable(bool isDragable)
{
    this->mIsDragable = isDragable;
}

bool DragAble::isDragable() const
{
    return this->mIsDragable;
}

bool DragAble::isBeingDragged()
{
    return this->mIsBeingDragged;
}

void DragAble::startDrag(DrawAbleObject* drawAble, int x, int y)
{
    this->oldX = drawAble->getX();
    this->oldY = drawAble->getY();
    this->mTransformX = oldX - x;
    this->mTransformY = oldY - y;
    this->mIsBeingDragged = true;
}

void DragAble::updateDragPos(DrawAbleObject* drawAble, int x, int y)
{
    drawAble->setX(x + mTransformX);
    drawAble->setY(y + mTransformY);
}

void DragAble::cancelDrag(DrawAbleObject* drawAble)
{
    drawAble->setX(this->oldX);
    drawAble->setY(this->oldY);
    this->mIsBeingDragged = false;
}

void DragAble::stopDrag()
{
    this->mIsBeingDragged = false;
}
