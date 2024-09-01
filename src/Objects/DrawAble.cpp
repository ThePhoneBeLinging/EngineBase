//
// Created by Elias Aggergaard Larsen on 01/09/2024.
//

#include "DrawAble.h"

#include "Controllers/TextureController.h"

DrawAble::DrawAble(float x, float y, int z, int width, int height, int textureIndex) : x_(x), y_(y), z_(z),
    width_(width), height_(height), textureIndex_(textureIndex)
{
}

DrawAble::DrawAble() : x_(0), y_(0), z_(0), width_(0), height_(0), textureIndex_(0)
{
}

void DrawAble::draw()
{
    TextureController::drawTexture(this);
}

float DrawAble::x() const
{
    return x_;
}

void DrawAble::x(float x)
{
    x_ = x;
}

float DrawAble::y() const
{
    return y_;
}

void DrawAble::y(float y)
{
    y_ = y;
}

int DrawAble::z() const
{
    return z_;
}

void DrawAble::z(int z)
{
    z_ = z;
}

int DrawAble::width() const
{
    return width_;
}

void DrawAble::width(int width)
{
    width_ = width;
}

int DrawAble::height() const
{
    return height_;
}

void DrawAble::height(int height)
{
    height_ = height;
}

int DrawAble::texture_index() const
{
    return textureIndex_;
}

void DrawAble::texture_index(int texture_index)
{
    textureIndex_ = texture_index;
}
