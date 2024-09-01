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
    [[nodiscard]] float x() const;
    void x(float x);
    [[nodiscard]] float y() const;
    void y(float y);
    [[nodiscard]] int z() const;
    void z(int z);
    [[nodiscard]] int width() const;
    void width(int width);
    [[nodiscard]] int height() const;
    void height(int height);
    [[nodiscard]] int textureIndex() const;
    void textureIndex(int texture_index);

    [[nodiscard]] bool isPointInside(float x, float y) const;

protected:
    float x_;
    float y_;
    int z_;
    int width_;
    int height_;
    int textureIndex_;
};


#endif //DRAWABLE_H
