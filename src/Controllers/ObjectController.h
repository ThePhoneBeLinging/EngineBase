//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H

#include <list>
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
    static void handleDeletions();
    static void sortScene(int scene);

private:
    static std::vector<std::list<DrawAbleObject*>> mAllDrawables;
    static std::vector<std::list<Button*>> mButtons;
    static std::list<DrawAbleObject*> mToBeDeleted;
    static std::list<Button*> mButtonsToBeDeleted;
    static DrawAbleObject* mDraggedDrawAble;
    static void drawAllObjects();
    static void handleClicks();

    static int mScene;
};


#endif //OBJECTCONTROLLER_H
