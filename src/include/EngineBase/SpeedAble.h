//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef SPEEDABLE_H
#define SPEEDABLE_H
#include "DrawAble.h"


class SpeedAble
{
public:
    explicit SpeedAble(DrawAble* drawAble);
    ~SpeedAble();
    void xSpeed(float xSpeed);
    void ySpeed(float ySpeed);
    [[nodiscard]] float xSpeed() const;
    [[nodiscard]] float ySpeed() const;
    void update(float deltaTime);

private:
    DrawAble* drawAble_;
    float xSpeed_;
    float ySpeed_;
};


#endif //SPEEDABLE_H
