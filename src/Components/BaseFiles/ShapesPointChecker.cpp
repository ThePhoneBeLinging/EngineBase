//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "ShapesPointChecker.h"


bool ShapesPointChecker::rectanglePointInsideChecker(Object *object, int x, int y)
{
    return object->getX() < x && x < (object->getX() + object->getWidth()) && object->getY() < y && y < object->getY() +
                                                                                                        object->getHeight();
}

bool ShapesPointChecker::rectangleCollisionChecker(DrawAbleObject *drawAbleObject, DrawAbleObject *otherObject)
{
    int x1 = drawAbleObject->getX();
    int x2 = drawAbleObject->getX() + drawAbleObject->getWidth();

    int y1 = drawAbleObject->getY();
    int y2 = drawAbleObject->getY() + drawAbleObject->getHeight();


    return otherObject->isPointInside(x1, y1) || otherObject->isPointInside(x2, y1) ||
           otherObject->isPointInside(x1, y2) || otherObject->isPointInside(x2, y2);
}
