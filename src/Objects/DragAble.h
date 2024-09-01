//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef DRAGABLE_H
#define DRAGABLE_H
#include "DrawAble.h"


class DragAble
{
public:
    explicit DragAble(DrawAble* drawAble);
    void startDrag();
    void cancelDrag();
    void updateDrag(float x, float y);

private:
    DrawAble* drawAble_;
    float oldX_;
    float oldY_;
};


#endif //DRAGABLE_H
