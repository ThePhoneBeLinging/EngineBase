//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H
#include <list>
#include <thread>
#include <raylib.h>
#include "DrawAbleObject.h"


class ObjectController
{
public:
    static void addDrawAbleObject(DrawAbleObject* drawAble);
    static void keepDrawingObjects();

private:
    static std::list<DrawAbleObject*> drawAbles;
    static void drawAllObjects();
};


#endif //OBJECTCONTROLLER_H
