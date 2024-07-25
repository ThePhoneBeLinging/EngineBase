//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H

#include <list>
#include <PointCheckerObject.h>
#include <thread>
#include <raylib.h>

#include "Button.h"
#include "DrawAbleObject.h"


class ObjectController
{
public:
    static void addDrawAbleObject(DrawAbleObject* drawAble);
    static void addButton(Button* button);
    static void keepDrawingObjects();

private:
    static std::list<DrawAbleObject*> drawAbles;
    static std::list<Button*> buttons;
    static void drawAllObjects();
    static void handleClicks();
};


#endif //OBJECTCONTROLLER_H
