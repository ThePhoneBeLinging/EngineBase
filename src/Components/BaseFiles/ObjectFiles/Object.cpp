//
// Created by Elias Aggergaard Larsen on 27/07/2024.
//

#include "Object.h"

#include "BaseFiles/ShapesPointChecker.h"

Object::Object(int x, int y, int height, int width)
{
    this->x = x;
    this->y = y;
    this->mHeight = height;
    this->mWidth = width;
}

void Object::setX(int x)
{
    this->x = x;
}

void Object::setY(int y)
{
    this->y = y;
}

void Object::setHeight(int height)
{
    this->mHeight = height;
}

void Object::setWidth(int width)
{
    this->mWidth = width;
}

int Object::getX() const
{
    return x;
}

int Object::getY() const
{
    return y;
}


int Object::getHeight() const
{
    return mHeight;
}

int Object::getWidth() const
{
    return mWidth;
}

bool Object::isPointInside(int x, int y)
{
    return ShapesPointChecker::rectanglePointInsideChecker(this, x, y);
}
