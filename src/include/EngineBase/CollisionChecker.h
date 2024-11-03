//
// Created by Elias Aggergaard Larsen on 03/11/2024.
//

#ifndef COLLISIONCHECKER_H
#define COLLISIONCHECKER_H
#include <memory>

#include "DrawAble.h"


class CollisionChecker
{
public:
    static bool checkSquareCollision(const std::shared_ptr<DrawAble>& firstDrawAble, const std::shared_ptr<DrawAble>& secondDrawAble);
};



#endif //COLLISIONCHECKER_H
