//
// Created by eal on 10/30/24.
//

#include "DrawAble.h"

DrawAble::DrawAble() : x_(0), y_(0), width_(0), height_(0), textureIndex_(0), id_(nullptr)
{
}

int DrawAble::getX() const
{
    return x_;
}

void DrawAble::setX(int x)
{
    x_ = x;
}

int DrawAble::getY() const
{
    return y_;
}

void DrawAble::setY(int y)
{
    y_ = y;
}

int DrawAble::getWidth() const
{
    return width_;
}

void DrawAble::setWidth(int width)
{
    width_ = width;
}

int DrawAble::getHeight() const
{
    return height_;
}

void DrawAble::setHeight(int height)
{
    height_ = height;
}

int DrawAble::getTextureIndex() const
{
    return textureIndex_;
}

void DrawAble::setTextureIndex(int texture_index)
{
    textureIndex_ = texture_index;
}

int* DrawAble::getID() const
{
    return id_;
}

void DrawAble::setID(int* id)
{
    id_ = id;
}

void DrawAble::subscribe(const std::function<void()>& callback)
{
    statusSubscribedFunctions_.push_back(callback);
}
