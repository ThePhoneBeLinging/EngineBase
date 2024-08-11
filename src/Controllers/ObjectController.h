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
    static void keepDrawingObjects();
    static void handleDeletions();
    static void sortScene(int scene);
    static bool isKeyPressed(int key);
    static bool isKeyDown(int key);
    static bool isKeyUp(int key);
    static bool isKeyReleased(int key);
    static SceneManager mSceneManager;

private:
    static std::vector<std::list<DrawAbleObject*>> mAllDrawables;
    static std::list<DrawAbleObject*> mToBeDeleted;
    static DrawAbleObject* mDraggedDrawAble;
    static void drawAllObjects();
    static void handleClicks();
    static std::mutex mMutex;
};


#endif //OBJECTCONTROLLER_H
