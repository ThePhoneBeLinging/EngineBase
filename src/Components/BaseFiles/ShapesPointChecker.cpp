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

    for (int i = drawAbleObject->getY(); i < y2; i++)
    {
        if (otherObject->isPointInside(x1, i) || otherObject->isPointInside(x2, i))
        {
            return true;
        }
    }
    for (int k = drawAbleObject->getX(); k < x2; k++)
    {
        if (otherObject->isPointInside(k, y1) || otherObject->isPointInside(k, y2))
        {
            return true;
        }
    }


    return false;
}
