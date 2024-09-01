//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H
#include <vector>

#include "Objects/DrawAble.h"


class ObjectController
{
public:
    static void update();
    static void addDrawAble(DrawAble* drawAble);

private:
    static void drawObjects();
    static inline std::vector<DrawAble*> drawAbles_;
};


#endif //OBJECTCONTROLLER_H
