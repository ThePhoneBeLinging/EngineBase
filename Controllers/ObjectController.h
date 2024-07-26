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
    static void removeObject(DrawAbleObject* drawAble);
    static void removeButton(Button* button);
    static void addButton(Button* button);
    static void keepDrawingObjects();
    static void setScene(int scene);
    static int getScene();

private:
    static std::list<DrawAbleObject*> drawAbles;
    static std::list<Button*> buttons;
    static std::list<DrawAbleObject*> toBeDeleted;
    static std::list<Button*> buttonsToBeDeleted;
    static void drawAllObjects();
    static void handleClicks();
    static void handleDeletions();
    static int mScene;
};


#endif //OBJECTCONTROLLER_H
