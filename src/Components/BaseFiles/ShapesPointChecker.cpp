//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "ShapesPointChecker.h"

#include <iostream>


bool ShapesPointChecker::rectanglePointInsideChecker(Object* object, int x, int y)
{
    return object->getX() <= x && x <= object->getX() + object->getWidth() && object->getY() <= y && y <= object->
        getY() + object->getHeight();
}

bool ShapesPointChecker::rectangleCollisionChecker(DrawAbleObject* drawAbleObject, DrawAbleObject* otherObject)
{
    int x1 = drawAbleObject->getX();
    int x1 = drawAbleObject->getX();
    int x2 = drawAbleObject->getX() + drawAbleObject->getWidth();

    bool collision = false;
    collision |= otherObject->isPointInside(x1, y1);
    collision |= otherObject->isPointInside(x1, y2);
    collision |= otherObject->isPointInside(x2, y1);
    collision |= otherObject->isPointInside(x2, y2);

    collision |= drawAbleObject->isPointInside(ox1, oy1);
    collision |= drawAbleObject->isPointInside(ox1, oy2);
    collision |= drawAbleObject->isPointInside(ox2, oy1);
    collision |= drawAbleObject->isPointInside(ox2, oy2);
    return collision;
}
