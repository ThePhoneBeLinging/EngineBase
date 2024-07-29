//
// Created by Elias Aggergaard Larsen on 27/07/2024.
//

#ifndef DRAGABLE_H
#define DRAGABLE_H

class DrawAbleObject;

class DragAble
{
public:
    DragAble() = default;
    void setDragable(bool isDragable);
    bool isDragable() const;
    bool isBeingDragged();
    void startDrag(DrawAbleObject* drawAble);
    void cancelDrag(DrawAbleObject* drawAble);
    void stopDrag();

private:
    bool mIsDragable = false;
    bool mIsBeingDragged = false;
    int oldX;
    int oldY;
};


#endif //DRAGABLE_H
