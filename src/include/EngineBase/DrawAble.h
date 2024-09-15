//
// Created by Elias Aggergaard Larsen on 01/09/2024.
//

#ifndef DRAWABLE_H
#define DRAWABLE_H


class DrawAble
{
public:
    DrawAble(float x, float y, int z, int width, int height, int textureIndex = 0);
    DrawAble();
    virtual ~DrawAble();
    void draw();
    [[nodiscard]] virtual float x() const;
    virtual void x(float x);
    [[nodiscard]] virtual float y() const;
    virtual void y(float y);
    [[nodiscard]] virtual int z() const;
    virtual void z(int z);
    [[nodiscard]] virtual int width() const;
    virtual void width(int width);
    [[nodiscard]] virtual int height() const;
    virtual void height(int height);
    [[nodiscard]] virtual int textureIndex() const;
    virtual void textureIndex(int texture_index);

    [[nodiscard]] virtual bool isPointInside(float x, float y) const;

protected:
    float x_;
    float y_;
    int z_;
    int width_;
    int height_;
    int textureIndex_;
};


#endif //DRAWABLE_H
