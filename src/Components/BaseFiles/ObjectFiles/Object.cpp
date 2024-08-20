//
// Created by Elias Aggergaard Larsen on 27/07/2024.
//

#include "Object.h"

#include <Controllers/ObjectController.h>
#include <cassert>
#include <utility>

#include "../ShapesPointChecker.h"

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
    assert(height >= 0);
    this->mHeight = height;
}

void Object::setWidth(int width)
{
    assert(width >= 0);
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

std::string Object::getID()
{
    return mID;
}

void Object::setID(std::string newID)
{
    mID = std::move(newID);
}
