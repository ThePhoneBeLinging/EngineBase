//
// Created by Elias Aggergaard Larsen on 10/08/2024.
//

#include "Line.h"

Line::Line(int x, int y, int height, int width) : DrawAbleObject(x, y, height, width)
{
}

void Line::draw()
{
    DrawRectangle(x, y, mWidth * (1000 / GetScreenWidth()), mHeight * (1000 / GetScreenHeight()), BLACK);
}
