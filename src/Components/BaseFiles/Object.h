//
// Created by Elias Aggergaard Larsen on 27/07/2024.
//

#ifndef OBJECT_H
#define OBJECT_H


class Object
{
public:
    Object(int x, int y, int height, int width);
    void setX(int x);
    void setY(int y);
    void setHeight(int height);
    void setWidth(int width);
    int getX() const;
    int getY() const;
    int getHeight() const;
    int getWidth() const;
    virtual bool isPointInside(int x, int y);

protected:
    int x;
    int y;
    int mHeight;
    int mWidth;
};


#endif //OBJECT_H
