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
    explicit ClickAble(DrawAble* drawAble);
    void setOnClick(std::function<void(DrawAble*)>);
    void onClick();

private:
    DrawAble* drawAble_;
    std::function<void(DrawAble*)> onClickFunction_;
};


#endif //CLICKABLE_H
