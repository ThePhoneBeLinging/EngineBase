//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "TestButton.h"

#include <iostream>

TestButton::TestButton(int x, int y, int height, int width,
                       std::shared_ptr<TextureController>& textureController) : RectangleButton(
    x, y, height, width, textureController)
{
}

void TestButton::onClick()
{
    this->deleteObject();
}
