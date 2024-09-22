//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include "EngineBase/SpeedAble.h"

#include "Controllers/ObjectController.h"

SpeedAble::SpeedAble(DrawAble* drawAble) : drawAble_(drawAble), xSpeed_(0), ySpeed_(0), xTarget_(0), yTarget_(0)
{
}

SpeedAble::~SpeedAble()
= default;

void SpeedAble::xSpeed(float xSpeed)
{
    xSpeed_ = xSpeed;
}

void SpeedAble::ySpeed(float ySpeed)
{
    ySpeed_ = ySpeed;
}

float SpeedAble::x_target() const
{
    return xTarget_;
}

void SpeedAble::x_target(float x_target)
{
    xTarget_ = x_target;
}

float SpeedAble::y_target() const
{
    return yTarget_;
}

void SpeedAble::y_target(float y_target)
{
    yTarget_ = y_target;
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

    if (xSpeed_ > 0)
    {
        if (xTarget_ < drawAble_->x())
        {
            drawAble_->x(xTarget_);
            xSpeed_ = 0;
        }
    }
    else if (xSpeed_ < 0)
    {
        if (xTarget_ > drawAble_->x())
        {
            drawAble_->x(xTarget_);
            xSpeed_ = 0;
        }
    }

    if (ySpeed_ > 0)
    {
        if (yTarget_ < drawAble_->y())
        {
            drawAble_->y(yTarget_);
            ySpeed_ = 0;
        }
    }
    else if (ySpeed_ < 0)
    {
        if (yTarget_ > drawAble_->y())
        {
            drawAble_->y(yTarget_);
            ySpeed_ = 0;
        }
    }

    drawAble_->x(drawAble_->x() + xSpeed_ * deltaTime);
    drawAble_->y(drawAble_->y() + ySpeed_ * deltaTime);
}
