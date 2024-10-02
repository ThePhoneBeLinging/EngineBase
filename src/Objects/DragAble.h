//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef DRAGABLE_H
#define DRAGABLE_H

#include <functional>

#include "DrawAble.h"
#include "../Controllers/ObjectKeeper.h"

class DragAble
{
public:
    explicit DragAble(int drawAbleID);

    ~DragAble();

    void startDrag(float x, float y, std::function<void(int, int)>& callbackFunction);

    void cancelDrag();

    void updateDrag(float x, float y);

    [[nodiscard]] int getDrawAble() const;

private:
    int drawAbleID_;
    float oldX_;
    float oldY_;
    float offsetX_;
    float offsetY_;
    std::function<void(int, int)> callbackFunction_;
};


#endif //DRAGABLE_H
