//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H

#include <list>
#include <vector>
#include "ObjectKeeper.h"
#include "Objects/DrawAble.h"

#include <memory>


class ObjectController
{
public:
    static void update(float deltaTime);

    static void addDrawAble(int id);

    static void keepDrawing();

    static void sortDrawAbles();

private:
    static void drawObjects();

    static inline std::mutex drawAblesMutex;

    static inline std::vector<int> drawAbles_;
};


#endif //OBJECTCONTROLLER_H
