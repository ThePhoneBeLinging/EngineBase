//
// Created by eal on 10/30/24.
//

#include "EngineBase/DrawAble.h"

DrawAble::DrawAble() : x_(0), y_(0), z_(0), width_(0), height_(0), textureIndex_(0), id_(-1),
                       mutex_(std::make_unique<std::mutex>())
{
    drawAble_ = std::make_shared<DrawAble>(this);
}

DrawAble::DrawAble(const DrawAble* drawAble)
{
    x_ = drawAble->getX();
    y_ = drawAble->getY();
    z_ = drawAble->getZ();
    width_ = drawAble->getWidth();
    height_ = drawAble->getHeight();
    textureIndex_ = drawAble->getTextureIndex();
    id_ = drawAble->getID();
    drawAble_ = nullptr;
    mutex_ = std::make_unique<std::mutex>();
}

double DrawAble::getX() const
{
    std::lock_guard lock(*mutex_);
    return x_;
}

void DrawAble::setX(double x)
{
    std::lock_guard lock(*mutex_);
    x_ = x;
    if (drawAble_ != nullptr)
    {
        drawAble_->setX(x);
    }
}

double DrawAble::getY() const
{
    std::lock_guard lock(*mutex_);
    return y_;
}

void DrawAble::setY(double y)
{
    std::lock_guard lock(*mutex_);
    y_ = y;
    if (drawAble_ != nullptr)
    {
        drawAble_->setY(y);
    }
}

int DrawAble::getZ() const
{
    std::lock_guard lock(*mutex_);
    return z_;
}

void DrawAble::setZ(int z)
{
    std::lock_guard lock(*mutex_);
    if (z_ != z)
    {
        z_ = z;
        if (drawAble_ != nullptr)
        {
            drawAble_->setZ(z);
        }
    }
}

int DrawAble::getWidth() const
{
    std::lock_guard lock(*mutex_);
    return width_;
}

void DrawAble::setWidth(int width)
{
    std::lock_guard lock(*mutex_);
    width_ = width;
    if (drawAble_ != nullptr)
    {
        drawAble_->setWidth(width);
    }
}

int DrawAble::getHeight() const
{
    std::lock_guard lock(*mutex_);
    return height_;
}

void DrawAble::setHeight(int height)
{
    std::lock_guard lock(*mutex_);
    if (drawAble_ != nullptr)
    {
        drawAble_->setHeight(height);
    }
    height_ = height;
}

int DrawAble::getTextureIndex() const
{
    std::lock_guard lock(*mutex_);
    return textureIndex_;
}

void DrawAble::setTextureIndex(int textureIndex)
{
    std::lock_guard lock(*mutex_);
    if (drawAble_ != nullptr)
    {
        drawAble_->setTextureIndex(textureIndex);
    }
    textureIndex_ = textureIndex;
}

int DrawAble::getID() const
{
    std::lock_guard lock(*mutex_);
    return id_;
}

void DrawAble::setID(int id)
{
    std::lock_guard lock(*mutex_);
    id_ = id;
    if (drawAble_ != nullptr)
    {
        drawAble_->setID(id);
    }
}

void DrawAble::setDrawAble(const std::shared_ptr<DrawAble>& drawAble)
{
    drawAble_ = drawAble;
}

std::weak_ptr<DrawAble> DrawAble::getDrawAblePtr() const
{
    return drawAble_;
}
