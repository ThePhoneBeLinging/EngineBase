//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "ShapesPointChecker.h"


bool ShapesPointChecker::rectanglePointInsideChecker(Object* object, int x, int y)
{
    return object->getX() < x && x < (object->getX() + object->getWidth()) && object->getY() < y && y < object->getY() +
        object->getHeight();
}
