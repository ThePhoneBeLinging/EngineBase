//
// Created by eal on 10/23/24.
//

#include "SpeedAble.h"

#include "EngineBase/EngineBase.h"

SpeedAble::SpeedAble(int id, int xSpeed, int ySpeed)
{
    this->id_ = id;
    this->xSpeed_ = xSpeed;
    this->ySpeed_ = ySpeed;
}

void SpeedAble::update(float deltaTime) const
{
    auto drawAble = EngineBase::getDrawAble(id_);
    drawAble->x(drawAble->x() + (xSpeed_ * deltaTime));
    drawAble->y(drawAble->y() + (ySpeed_ * deltaTime));
    EngineBase::doneWriting();
}

int SpeedAble::id() const
{
    return  id_;
}
