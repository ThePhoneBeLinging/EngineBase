//
// Created by Elias Aggergaard Larsen on 27/07/2024.
//

#include "DragAble.h"

void DragAble::setDragable(bool isDragable)
{
    this->mIsDragable = isDragable;
}

bool DragAble::isDragable()
{
    return this->mIsDragable;
}
