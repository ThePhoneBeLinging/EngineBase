#include <Controllers/TextureController.h>
#include "DrawAble.h"

DrawAble::DrawAble(float x, float y, int z, int width, int height, int textureIndex)
        : x_(x), y_(y), z_(z), width_(width), height_(height), textureIndex_(textureIndex), id_(-1)
{}

DrawAble::DrawAble() : x_(0), y_(0), z_(0), width_(0), height_(0), textureIndex_(0), id_(-1)
{}


DrawAble::DrawAble(const DrawAble &other) : x_(other.x_), y_(other.y_), z_(other.z_), width_(other.width_), height_(other.height_), textureIndex_(other.textureIndex_), id_(other.id_)
{}

DrawAble::~DrawAble() = default;

void DrawAble::draw()
{
    std::shared_lock lock(drawAbleMutex_);
    TextureController::drawTexture(x_, y_, width_, height_, textureIndex_);
}

float DrawAble::x()
{
    std::shared_lock lock(drawAbleMutex_);
    return x_;
}

void DrawAble::x(float x)
{
    std::lock_guard<std::shared_mutex> lock(drawAbleMutex_);
    x_ = x;
}

float DrawAble::y()
{
    std::shared_lock lock(drawAbleMutex_);
    return y_;
}

void DrawAble::y(float y)
{
    std::lock_guard lock(drawAbleMutex_);
    y_ = y;
}

int DrawAble::z()
{
    std::shared_lock lock(drawAbleMutex_);
    return z_;
}

void DrawAble::z(int z)
{
    std::lock_guard lock(drawAbleMutex_);
    z_ = z;
}

int DrawAble::width()
{
    std::shared_lock lock(drawAbleMutex_);
    return width_;
}

void DrawAble::width(int width)
{
    std::lock_guard lock(drawAbleMutex_);
    width_ = width;
}

int DrawAble::height()
{
    std::shared_lock lock(drawAbleMutex_);
    return height_;
}

void DrawAble::height(int height)
{
    std::lock_guard lock(drawAbleMutex_);
    height_ = height;
}

int DrawAble::textureIndex()
{
    std::shared_lock lock(drawAbleMutex_);
    return textureIndex_;
}

void DrawAble::textureIndex(int texture_index)
{
    std::lock_guard lock(drawAbleMutex_);
    textureIndex_ = texture_index;
}

bool DrawAble::isPointInside(float x, float y)
{
    std::shared_lock lock(drawAbleMutex_);
    return x >= x_ && x <= x_ + static_cast<float>(width_) && y >= y_ && y <= y_ + static_cast<float>(height_);
}

void DrawAble::id(int id)
{
    std::lock_guard lock(drawAbleMutex_);
    id_ = id;
}

int DrawAble::id()
{
    std::shared_lock lock(drawAbleMutex_);
    return id_;
}

