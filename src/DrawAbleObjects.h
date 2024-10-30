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
    static void addDrawAble(const std::shared_ptr<DrawAble>& drawAble);
    static void markDrawAbleAsOnScreen(const std::shared_ptr<DrawAble>& drawAble);
    static void removeDrawAble(const std::shared_ptr<DrawAble>& drawAble);
    static void markDrawAbleAsOffScreen(const std::shared_ptr<DrawAble>& drawAble);

private:
    static inline std::list<std::shared_ptr<DrawAble>> drawAbles_;
    static inline std::list<std::shared_ptr<DrawAble>> activeDrawAbles_;
    static inline std::list<std::shared_ptr<DrawAble>> offScreenDrawAbles_;
};


#endif //DRAWABLEOBJECTS_H
