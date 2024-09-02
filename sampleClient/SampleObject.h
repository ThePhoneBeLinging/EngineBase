//
// Created by Elias Aggergaard Larsen on 01/09/2024.
//

#ifndef SAMPLEOBJECT_H
#define SAMPLEOBJECT_H
#include "EngineBase/DragAble.h"
#include "EngineBase/DrawAble.h"
#include "EngineBase/SpeedAble.h"


class SampleObject : public DrawAble
{
public:
    SampleObject();

private:
    DragAble dragAble_;
    SpeedAble speedAble_;
};


#endif //SAMPLEOBJECT_H
