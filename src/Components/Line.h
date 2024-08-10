//
// Created by Elias Aggergaard Larsen on 10/08/2024.
//

#ifndef LINE_H
#define LINE_H
#include <DrawAbleObject.h>


class Line : public DrawAbleObject
{
public:
    Line(int x, int y, int height, int width);
    void draw() override;
};


#endif //LINE_H
