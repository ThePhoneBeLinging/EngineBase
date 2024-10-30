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
    static void activateDrawAble(std::shared_ptr<DrawAble>);

private:
    static inline std::list<std::shared_ptr<DrawAble>> drawAbles_;
    static inline std::list<std::shared_ptr<DrawAble>> activeDrawAbles_;
    static inline std::list<std::shared_ptr<DrawAble>> offScreenDrawAbles_;
    static inline std::list<std::shared_ptr<DrawAble>> inactiveDrawAbles_;
};


#endif //DRAWABLEOBJECTS_H
