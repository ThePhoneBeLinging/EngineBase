//
// Created by Elias Aggergaard Larsen on 01/09/2024.
//

#include "SampleObject.h"

SampleObject::SampleObject() : DrawAble(0, 0, 0, 50, 50, 0), dragAble_(this), speedAble_(this)
{
    speedAble_.xSpeed(10.0);
}
