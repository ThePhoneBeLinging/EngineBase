//
// Created by Elias Aggergaard Larsen on 03/11/2024.
//

#include "include/EngineBase/CollisionChecker.h"


bool CollisionChecker::checkSquareCollision(const std::shared_ptr<DrawAble>& firstDrawAble, const std::shared_ptr<DrawAble>& secondDrawAble)
{

    if (firstDrawAble->getX() + firstDrawAble->getWidth() < secondDrawAble->getX())
    {
        return false;
    }

    if (firstDrawAble->getY() + firstDrawAble->getHeight() < secondDrawAble->getY())
    {
        return false;
    }

    if (secondDrawAble->getX() + secondDrawAble->getWidth() < firstDrawAble->getX())
    {
        return false;
    }

    if (secondDrawAble->getY() + secondDrawAble->getHeight() < firstDrawAble->getY())
    {
        return false;
    }

    return true;
}
