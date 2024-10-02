//
// Created by Elias Aggergaard Larsen on 05/09/2024.
//

#ifndef CLICKABLE_H
#define CLICKABLE_H
#include "DrawAble.h"
#include <functional>

class ClickAble
{
public:
    explicit ClickAble(int drawAbleID);
    void setOnClick(std::function<void()>);
    void onClick();
    int drawAble();

private:
    int drawAbleID_;
    std::function<void()> onClickFunction_;
};


#endif //CLICKABLE_H
