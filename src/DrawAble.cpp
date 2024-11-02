//
// Created by eal on 10/30/24.
//

#include "EngineBase/DrawAble.h"

#include "DrawAbleObjects.h"
#include "mutex"

DrawAble::DrawAble() : x_(0), y_(0), width_(0), height_(0), textureIndex_(0), id_(nullptr)
{
}

int DrawAble::getX() const
{
    std::lock_guard lock(mutex_);
    return x_;
}

void DrawAble::setX(int x)
{
    std::lock_guard lock(mutex_);
    x_ = x;
}

int DrawAble::getY() const
{
    std::lock_guard lock(mutex_);
    return y_;
}

void DrawAble::setY(int y)
{
    std::lock_guard lock(mutex_);
    y_ = y;
}

int DrawAble::getZ() const
{
    std::lock_guard lock(mutex_);
    return z_;
}

void DrawAble::setZ(int z)
{
    std::lock_guard lock(mutex_);
    if (z_ != z)
    {
        z_ = z;
        DrawAbleObjects::sortActiveDrawAbles();
    }
}

int DrawAble::getWidth() const
{
    std::lock_guard lock(mutex_);
    return width_;
}

void DrawAble::setWidth(int width)
{
    std::lock_guard lock(mutex_);
    width_ = width;
}

int DrawAble::getHeight() const
{
    std::lock_guard lock(mutex_);
    return height_;
}

void DrawAble::setHeight(int height)
{
    std::lock_guard lock(mutex_);
    height_ = height;
}

int DrawAble::getTextureIndex() const
{
    std::lock_guard lock(mutex_);
    return textureIndex_;
}

void DrawAble::setTextureIndex(int texture_index)
{
    std::lock_guard lock(mutex_);
    textureIndex_ = texture_index;
}

int* DrawAble::getID() const
{
    std::lock_guard lock(mutex_);
    return id_;
}

void DrawAble::setID(int* id)
{
    std::lock_guard lock(mutex_);
    id_ = id;
}

void DrawAble::markAsOffScreen() const
{
    DrawAbleObjects::markDrawAbleAsOffScreen(*id_);
}

void DrawAble::markAsOnScreen() const
{
    DrawAbleObjects::markDrawAbleAsOnScreen(*id_);
}
