//
// Created by eal on 10/30/24.
//

#include "EngineBase/DrawAble.h"

DrawAble::DrawAble() : x_(0), y_(0),z_(0), width_(0), height_(0), textureIndex_(0), id_(-1)
{
}

double DrawAble::getX() const
{
    std::lock_guard lock(mutex_);
    return x_;
}

void DrawAble::setX(double x)
{
    std::lock_guard lock(mutex_);
    x_ = x;
}

double DrawAble::getY() const
{
    std::lock_guard lock(mutex_);
    return y_;
}

void DrawAble::setY(double y)
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
    std::unique_lock lock(mutex_);
    if (z_ != z)
    {
        z_ = z;
        //lock.unlock();
        //DrawAbleObjects::sortActiveDrawAbles();
        //lock.lock();
    }
    lock.unlock();
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

void DrawAble::setTextureIndex(int textureIndex)
{
    std::lock_guard lock(mutex_);
    textureIndex_ = textureIndex;
}

int DrawAble::getID() const
{
    std::lock_guard lock(mutex_);
    return id_;
}

void DrawAble::setID(int id)
{
    std::lock_guard lock(mutex_);
    id_ = id;
}