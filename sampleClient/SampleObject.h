//
// Created by Elias Aggergaard Larsen on 01/09/2024.
//

#ifndef SAMPLEOBJECT_H
#define SAMPLEOBJECT_H
#include "Objects/DragAble.h"
#include "Objects/DrawAble.h"


class SampleObject : public DrawAble
{
public:
    SampleObject();

private:
    DragAble dragAble_;
};


#endif //SAMPLEOBJECT_H
