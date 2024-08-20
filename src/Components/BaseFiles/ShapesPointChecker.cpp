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
    int x2 = drawAbleObject->getX() + drawAbleObject->getWidth();
    int y1 = drawAbleObject->getY();
    int y2 = drawAbleObject->getY() + drawAbleObject->getHeight();

    int otherX1 = otherObject->getX();
    int otherX2 = otherObject->getX() + otherObject->getWidth();
    int otherY1 = otherObject->getY();
    int otherY2 = otherObject->getY() + otherObject->getHeight();


    bool collision = otherObject->isPointInside(x1, y1);
    collision |= otherObject->isPointInside(x2, y1);
    collision |= otherObject->isPointInside(x1, y2);
    collision |= otherObject->isPointInside(x2, y2);
    if (collision) return true;
    collision |= drawAbleObject->isPointInside(otherX1, otherY1);
    collision |= drawAbleObject->isPointInside(otherX2, otherY1);
    collision |= drawAbleObject->isPointInside(otherX1, otherY2);
    collision |= drawAbleObject->isPointInside(otherX2, otherY2);
    return collision;
}
