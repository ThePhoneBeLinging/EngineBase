//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#include "Collidable.h"

Collidable::Collidable(DrawAble *drawAble) : drawAble_(drawAble)
{
}

bool Collidable::isColliding(Collidable *collidable)
{
    auto x1 = drawAble_->x();
    auto x2 = drawAble_->x() + drawAble_->width();
    auto y1 = drawAble_->y();
    auto y2 = drawAble_->y() + drawAble_->height();

    auto otherx1 = collidable->drawAble_->x();
    auto otherx2 = collidable->drawAble_->x() + collidable->drawAble_->width();
    auto othery1 = collidable->drawAble_->y();
    auto othery2 = collidable->drawAble_->y() + collidable->drawAble_->height();

    bool collision = false;
    collision |= collidable->drawAble_->isPointInside(x1, y1);
    collision |= collidable->drawAble_->isPointInside(x1, y2);
    collision |= collidable->drawAble_->isPointInside(x2, y1);
    collision |= collidable->drawAble_->isPointInside(x2, y2);

    collision |= drawAble_->isPointInside(otherx1, othery1);
    collision |= drawAble_->isPointInside(otherx1, othery2);
    collision |= drawAble_->isPointInside(otherx2, othery1);
    collision |= drawAble_->isPointInside(otherx2, othery2);

    return collision;
}
