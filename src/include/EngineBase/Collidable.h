//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef COLLIDABLE_H
#define COLLIDABLE_H
#include "DrawAble.h"


class Collidable
{
public:
    explicit Collidable(DrawAble* drawAble);
    bool isColliding(Collidable* collidable);

protected:
    DrawAble* drawAble_;
};


#endif //COLLIDABLE_H
