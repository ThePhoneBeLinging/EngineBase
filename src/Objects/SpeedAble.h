//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef SPEEDABLE_H
#define SPEEDABLE_H

#include "Objects/DrawAble.h"


class SpeedAble
{
public:
    explicit SpeedAble(DrawAble *drawAble);

    ~SpeedAble();

    void xSpeed(float xSpeed);

    void ySpeed(float ySpeed);

    void x_target(float x_target);

    void y_target(float y_target);

    [[nodiscard]] float xSpeed() const;

    [[nodiscard]] float ySpeed() const;

    [[nodiscard]] float x_target() const;

    [[nodiscard]] float y_target() const;

    void update(float deltaTime);

    DrawAble *drawAble_;
private:
    float xSpeed_;
    float ySpeed_;
    float xTarget_;
    float yTarget_;
};


#endif //SPEEDABLE_H
