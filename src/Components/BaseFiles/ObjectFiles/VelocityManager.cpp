//
// Created by Elias on 20/08/2024.
//

#include "VelocityManager.h"
#include "EngineBase/DrawAbleObject.h"

VelocityManager::VelocityManager(DrawAbleObject *drawAbleObject)
{
    this->mDrawAbleObject = drawAbleObject;
}

void VelocityManager::setVelocity(int xSpeed, int ySpeed)
{
    this->mXSpeed = xSpeed;
    this->mYSpeed = ySpeed;
}

void VelocityManager::updatePosition()
{
    this->mDrawAbleObject->setX(this->mDrawAbleObject->getX() + this->mXSpeed);
    this->mDrawAbleObject->setY(this->mDrawAbleObject->getY() + this->mYSpeed);
}
