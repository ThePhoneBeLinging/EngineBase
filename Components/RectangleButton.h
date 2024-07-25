//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef RECTANGLEBUTTON_H
#define RECTANGLEBUTTON_H
#include "Button.h"
#include "RectangleObject.h"


class RectangleButton : public RectangleObject, public Button
{
    RectangleButton(int x, int y, int height, int width, std::shared_ptr<TextureController>& textureController);
};


#endif //RECTANGLEBUTTON_H
