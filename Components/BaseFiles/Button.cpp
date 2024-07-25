//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "Button.h"

#include <ObjectController.h>

Button::Button(int x, int y, int height, int width,
               std::shared_ptr<TextureController>& textureController) : PointCheckerObject(
    x, y, height, width, textureController)
{
    ObjectController::addButton(this);
}
