//
// Created by Elias Aggergaard Larsen on 27/07/2024.
//

#ifndef DRAGABLE_H
#define DRAGABLE_H


class DragAble
{
public:
    DragAble() = default;
    void setDragable(bool isDragable);
    bool isDragable();

private:
    bool mIsDragable = false;
};


#endif //DRAGABLE_H
