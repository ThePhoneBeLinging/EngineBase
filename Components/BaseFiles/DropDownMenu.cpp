//
// Created by Elias Aggergaard Larsen on 26/07/2024.
//

#include "DropDownMenu.h"

DropDownMenu::DropDownMenu(int x, int y, int height, int width,
                           std::shared_ptr<TextureController>& textureController) : DrawAbleObject(
    x, y, height, width, textureController)
{
}
