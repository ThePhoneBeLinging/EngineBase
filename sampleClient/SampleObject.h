//
// Created by Elias Aggergaard Larsen on 01/09/2024.
//

#ifndef SAMPLEOBJECT_H
#define SAMPLEOBJECT_H

#include "Objects/ClickAble.h"

#include "Objects/DragAble.h"
#include "Objects/DrawAble.h"
#include "Objects/SpeedAble.h"


class SampleObject : public DrawAble
{
public:
    SampleObject();

    SpeedAble speedAble_;
    ClickAble clickAble_;

};


#endif //SAMPLEOBJECT_H
