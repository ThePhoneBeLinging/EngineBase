//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "RectangleButton.h"

#include "ShapesPointChecker.h"

RectangleButton::RectangleButton(int x, int y, int height, int width,
                                 std::shared_ptr<TextureController>& textureController) : Button(
    x, y, height, width, textureController)
{
}

bool RectangleButton::isPointInside(int xToCheck, int yToCheck)
{
    return ShapesPointChecker::rectanglePointInsideChecker(this, xToCheck, yToCheck);
}

