//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H
#include <vector>


#include "EngineBase/ClickAble.h"

#include "EngineBase/DragAble.h"
#include "EngineBase/DrawAble.h"
#include "EngineBase/SpeedAble.h"


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

    static void addClickAble(ClickAble* clickAble);
    static void removeClickAble(ClickAble* clickAble);


private:
    static void drawObjects();
    static void handleClicks();
    static void updateSpeedAbles(float deltaTime);
    static void sortDrawAbles();
    static void sortDragAbles();

    static void sortClickAbles();
    static inline std::vector<DrawAble*> drawAbles_;
    static inline std::vector<DragAble*> dragAbles_;
    static inline std::vector<SpeedAble*> speedAbles_;
    static inline std::vector<ClickAble*> clickAbles_;

    static inline DragAble* currentDragged_ = nullptr;
};


#endif //OBJECTCONTROLLER_H
