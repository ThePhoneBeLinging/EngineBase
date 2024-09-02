//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H
#include <vector>

#include "Objects/DragAble.h"
#include "Objects/DrawAble.h"
#include "Objects/SpeedAble.h"


class ObjectController
{
public:
    static void update(float deltaTime);
    static void addDrawAble(DrawAble* drawAble);
    static void removeDrawAble(DrawAble* drawAble);
    static void addDragAble(DragAble* dragAble);
    static void removeDragAble(DragAble* dragAble);
    static void addSpeedAble(SpeedAble* speedAble);
    static void removeSpeedAble(SpeedAble* speedAble);

private:
    static void drawObjects();
    static void handleClicks();
    static void updateSpeedAbles(float deltaTime);
    static inline std::vector<DrawAble*> drawAbles_;
    static inline std::vector<DragAble*> dragAbles_;
    static inline std::vector<SpeedAble*> speedAbles_;
    static inline DragAble* currentDragged_ = nullptr;
};


#endif //OBJECTCONTROLLER_H
