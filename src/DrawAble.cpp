//
// Created by eal on 10/30/24.
//

#include <utility>

#include "EngineBase/DrawAble.h"

DrawAble::DrawAble() : x_(0), y_(0), z_(0), width_(0), height_(0), id_(-1), positionIsAffectedByOffset_(true),
                       mutex_(std::make_unique<std::mutex>())
{
    drawAble_ = std::make_shared<DrawAble>(this);
}

DrawAble::DrawAble(const DrawAble *drawAble)
{
    x_ = drawAble->getX();
    y_ = drawAble->getY();
    z_ = drawAble->getZ();
    width_ = drawAble->getWidth();
    height_ = drawAble->getHeight();
    textureLocation_ = drawAble->getTextureLocation();
    id_ = drawAble->getID();
    positionIsAffectedByOffset_ = drawAble->getPositionIsAffectedByOffset();
    drawAble_ = nullptr;
    mutex_ = std::make_unique<std::mutex>();
}

void DrawAble::setPosition(double x, double y)
{
    std::lock_guard<std::mutex> lock(*mutex_);
    x_ = x;
    y_ = y;
    if (drawAble_ != nullptr)
    {
        drawAble_->setPosition(x, y);
    }
}

void DrawAble::updatePosition(double deltaX, double deltaY)
{
    std::lock_guard lock(*mutex_);
    x_ += deltaX;
    y_ += deltaY;
    if (drawAble_ != nullptr)
    {
        drawAble_->setPosition(x_, y_);
    }
}

void DrawAble::setSize(int width, int height)
{
    std::lock_guard lock(*mutex_);
    width_ = width;
    height_ = height;
    if (drawAble_ != nullptr)
    {
        drawAble_->setSize(width_, height_);
    }
}

void DrawAble::setHeightPreserveAspectRatio(const int height)
{
    std::lock_guard lock(*mutex_);
    height_ = height;
    double aspectRatio = height / width_;
    width_ *= aspectRatio;
    if (drawAble_ != nullptr)
    {
        drawAble_->setSize(width_, height_);
    }
}

void DrawAble::setWidthPreserveAspectRatio(const int width)
{
    std::lock_guard lock(*mutex_);
    width_ = width;
    double aspectRatio = width / height_;
    height_ *= aspectRatio;
    if (drawAble_ != nullptr)
    {
        drawAble_->setSize(width_, height_);
    }
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

std::string DrawAble::getTextureLocation() const
{
    std::lock_guard lock(*mutex_);
    return textureLocation_;
}

void DrawAble::setTextureLocation(std::string textureLocation)
{
    std::lock_guard lock(*mutex_);
    if (drawAble_ != nullptr)
    {
        drawAble_->setTextureLocation(std::move(textureLocation));
    }
    textureLocation_ = textureLocation;
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

void DrawAble::setDrawAble(const std::shared_ptr<DrawAble> &drawAble)
{
    drawAble_ = drawAble;
}

std::weak_ptr<DrawAble> DrawAble::getDrawAblePtr() const
{
    return drawAble_;
}

void DrawAble::setPositionIsAffectedByOffset(bool positionIsAffectedByOffset)
{
    positionIsAffectedByOffset_ = positionIsAffectedByOffset;
    if (drawAble_ != nullptr)
    {
        drawAble_->setPositionIsAffectedByOffset(positionIsAffectedByOffset);
    }
}

bool DrawAble::getPositionIsAffectedByOffset() const
{
    return positionIsAffectedByOffset_;
}
