//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H
#include <vector>

#include "Objects/DragAble.h"
#include "Objects/DrawAble.h"


class ObjectController
{
public:
    static void update();
    static void addDrawAble(DrawAble* drawAble);
    static void removeDrawAble(DrawAble* drawAble);
    static void addDragAble(DragAble* dragAble);
    static void removeDragAble(DragAble* dragAble);

private:
    static void drawObjects();
    static void handleClicks();
    static inline std::vector<DrawAble*> drawAbles_;
    static inline std::vector<DragAble*> dragAbles_;
    static inline DragAble* currentDragged_ = nullptr;
};


#endif //OBJECTCONTROLLER_H
