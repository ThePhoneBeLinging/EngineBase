//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef RECTANGLEBUTTON_H
#define RECTANGLEBUTTON_H
#include <memory>
#include "DrawAbleObject.h"

#include "Button.h"


class RectangleButton : public Button
{
public:
    RectangleButton(int x, int y, int height, int width);
    bool isPointInside(int xToCheck, int yToCheck) override;
};


#endif //RECTANGLEBUTTON_H
