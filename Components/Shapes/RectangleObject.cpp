//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "RectangleObject.h"

RectangleObject::RectangleObject(int x, int y, int height, int width,
                                 std::shared_ptr<TextureController>& textureController) : PointCheckerObject(
    x, y, height, width, textureController)
{
}

bool RectangleObject::isPointInside(int xToCheck, int yToCheck)
{
    return xToCheck < x + mWidth && x < xToCheck && yToCheck < y + mHeight && y < yToCheck;
}
