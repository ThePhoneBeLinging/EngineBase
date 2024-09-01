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
    ~DragAble();
    void startDrag(float x, float y);
    void cancelDrag();
    void updateDrag(float x, float y);
    DrawAble* getDrawAble();

private:
    DrawAble* drawAble_;
    float oldX_;
    float oldY_;
    float offsetX_;
    float offsetY_;
};


#endif //DRAGABLE_H
