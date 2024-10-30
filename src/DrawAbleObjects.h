//
// Created by eal on 10/30/24.
//

#ifndef DRAWABLEOBJECTS_H
#define DRAWABLEOBJECTS_H
#include <list>
#include <memory>

#include "DrawAble.h"


class DrawAbleObjects
{
public:
    static int* addDrawAble(const std::shared_ptr<DrawAble>& drawAble);
    static void removeDrawAble(int id);
    static void markDrawAbleAsOnScreen(int id);
    static void markDrawAbleAsOffScreen(int id);

private:
    static inline std::list<int> drawAbleIds_;
    static inline std::vector<std::shared_ptr<DrawAble>> drawAbles_;
    static inline std::list<std::shared_ptr<DrawAble>> activeDrawAbles_;
};


#endif //DRAWABLEOBJECTS_H
