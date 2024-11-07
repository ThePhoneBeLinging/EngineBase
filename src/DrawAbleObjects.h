//
// Created by eal on 10/30/24.
//

#ifndef DRAWABLEOBJECTS_H
#define DRAWABLEOBJECTS_H
#include <list>
#include <memory>
#include <vector>

#include "EngineBase/DrawAble.h"

class DrawAbleObjects
{
public:
    static void addDrawAble(const std::shared_ptr<DrawAble>& drawAble);
    static void removeDrawAble(int id);
    static void sortActiveDrawAbles();
    static void markDrawAbleAsOnScreen(int id);
    static void markDrawAbleAsOffScreen(int id);
    static std::list<std::shared_ptr<DrawAble>>& getActiveDrawAbles();

private:
    static inline std::list<std::weak_ptr<DrawAble>> drawAbles_;
    static inline std::list<std::weak_ptr<DrawAble>> activeDrawAbles_;
};


#endif //DRAWABLEOBJECTS_H
