//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include "SpeedAble.h"

#include "Controllers/ObjectController.h"

SpeedAble::SpeedAble(DrawAble* drawAble) : drawAble_(drawAble), xSpeed_(0), ySpeed_(0)
{
    ObjectController::addSpeedAble(this);
}

SpeedAble::~SpeedAble()
{
    ObjectController::removeSpeedAble(this);
}

void SpeedAble::xSpeed(float xSpeed)
{
    xSpeed_ = xSpeed;
}

void SpeedAble::ySpeed(float ySpeed)
{
    ySpeed_ = ySpeed;
}

float SpeedAble::xSpeed() const
{
    return xSpeed_;
}

float SpeedAble::ySpeed() const
{
    return ySpeed_;
}

void SpeedAble::update(float deltaTime)
{
    drawAble_->x(drawAble_->x() + xSpeed_ * deltaTime);
    drawAble_->y(drawAble_->y() + ySpeed_ * deltaTime);
}
