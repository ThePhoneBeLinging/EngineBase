//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H

#include <list>
#include <vector>
#include "ObjectKeeper.h"

#include "Objects/ClickAble.h"

#include "Objects/DragAble.h"
#include "Objects/DrawAble.h"
#include "Objects/SpeedAble.h"
#include <memory>


class ObjectController
{
public:
    static void update(float deltaTime);

    static void addDrawAble(int id);

    static void keepDrawing();

    static void addDragAble(const std::weak_ptr<DragAble> &dragAble);

    static void addSpeedAble(const std::weak_ptr<SpeedAble> &speedAble);

    static void addClickAble(const std::weak_ptr<ClickAble> &clickAble);

    static void sortDrawAbles();

private:

    static void drawObjects();

    static void handleClicks();

    static void updateSpeedAbles(float deltaTime);

    static void sortDragAbles();

    static void sortClickAbles();

    static inline std::mutex drawAblesMutex;

    static inline std::vector<int> drawAbles_;
    static inline std::vector<std::weak_ptr<DragAble>> dragAbles_;
    static inline std::vector<std::weak_ptr<SpeedAble>> speedAbles_;
    static inline std::vector<std::weak_ptr<ClickAble>> clickAbles_;

    static inline std::weak_ptr<DragAble> *currentDragged_ = nullptr;
};


#endif //OBJECTCONTROLLER_H
