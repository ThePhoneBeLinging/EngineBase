//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "RectangleButton.h"

RectangleButton::RectangleButton(int x, int y, int height, int width,
                                 std::shared_ptr<TextureController>& textureController) : RectangleObject(
        x, y, height, width, textureController), Button()
{
}

