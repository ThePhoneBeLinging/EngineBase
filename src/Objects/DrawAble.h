//
// Created by Elias Aggergaard Larsen on 01/09/2024.
//

#ifndef DRAWABLE_H
#define DRAWABLE_H


#include <shared_mutex>
#include <mutex>

class DrawAble
{
public:
    DrawAble(float x, float y, int z, int width, int height, int textureIndex = 0);

    DrawAble();

    DrawAble(const DrawAble &);

    virtual ~DrawAble();

    void draw();

    [[nodiscard]] virtual float x();

    virtual void x(float x);

    [[nodiscard]] virtual float y();

    virtual void y(float y);

    [[nodiscard]] virtual int z();

    virtual void z(int z);

    [[nodiscard]] virtual int width();

    virtual void width(int width);

    [[nodiscard]] virtual int height();

    virtual void height(int height);

    [[nodiscard]] virtual int textureIndex();

    virtual void textureIndex(int texture_index);

    [[nodiscard]] virtual bool isPointInside(float x, float y);

    virtual void id(int id);

    [[nodiscard]] virtual int id();

protected:
    std::shared_mutex drawAbleMutex_;
    float x_;
    float y_;
    int z_;
    int width_;
    int height_;
    int textureIndex_;
    int id_;
};


#endif //DRAWABLE_H
