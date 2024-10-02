//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include "DragAble.h"

#include <utility>

DragAble::DragAble(int drawAbleID) : drawAbleID_(drawAbleID), oldX_(0), oldY_(0), offsetX_(0), offsetY_(0)
{
}

DragAble::~DragAble()
{
}

void DragAble::startDrag(float x, float y, std::function<void(int, int)>& callbackFunction)
{
    callbackFunction_ = std::move(callbackFunction);
    auto drawAble = ObjectKeeper::getDrawAbleForReading(drawAbleID_);
    this->offsetX_ = drawAble->x() - x;
    this->offsetY_ = drawAble->y() - y;
    updateDrag(x, y);
}

void DragAble::cancelDrag()
{
    auto drawAble = ObjectKeeper::getDrawAbleForWriting(drawAbleID_);
    drawAble->x(oldX_);
    drawAble->y(oldY_);
    ObjectKeeper::executeCommand(Command(PrimaryCMD::DONEWRITING));
}

void DragAble::updateDrag(float x, float y)
{
    auto drawAble = ObjectKeeper::getDrawAbleForWriting(drawAbleID_);
    drawAble->x(x + offsetX_);
    drawAble->y(y + offsetY_);
}

int DragAble::getDrawAble() const
{
    return drawAbleID_;
}
