//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "PointCheckerObject.h"

PointCheckerObject::PointCheckerObject(int x, int y, int height, int width,
                                       std::shared_ptr<TextureController>& textureController) : DrawAbleObject(
    x, y, height, width, textureController)
{
}
