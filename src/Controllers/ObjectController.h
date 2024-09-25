//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H
#include <list>
#include <vector>


#include "EngineBase/ClickAble.h"

#include "EngineBase/DragAble.h"
#include "EngineBase/DrawAble.h"
#include "EngineBase/SpeedAble.h"
#include <memory>


class ObjectController
{
public:
    static void update(float deltaTime);
    static void addDrawAble(const std::weak_ptr<DrawAble>& drawAble);
    static void addDrawAbles(const std::list<std::weak_ptr<DrawAble>>&);
    static void addDragAble(const std::weak_ptr<DragAble>& dragAble);
    static void addSpeedAble(const std::weak_ptr<SpeedAble>& speedAble);
    static void addClickAble(const std::weak_ptr<ClickAble>& clickAble);

private:
    static void drawObjects();
    static void handleClicks();
    static void updateSpeedAbles(float deltaTime);
    static void sortDrawAbles();
    static void sortDragAbles();
    static void sortClickAbles();
    static inline std::vector<std::weak_ptr<DrawAble>> drawAbles_;
    static inline std::vector<std::weak_ptr<DragAble>> dragAbles_;
    static inline std::vector<std::weak_ptr<SpeedAble>> speedAbles_;
    static inline std::vector<std::weak_ptr<ClickAble>> clickAbles_;

    static inline std::weak_ptr<DragAble>* currentDragged_ = nullptr;
};


#endif //OBJECTCONTROLLER_H
