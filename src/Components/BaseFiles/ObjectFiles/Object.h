//
// Created by Elias Aggergaard Larsen on 27/07/2024.
//

#ifndef OBJECT_H
#define OBJECT_H
#include "CollisionManager.h"


class Object
{
public:
    Object(int x, int y, int height, int width);
    virtual void setX(int x);
    virtual void setY(int y);
    void setHeight(int height);
    void setWidth(int width);
    int getX() const;
    int getY() const;
    int getHeight() const;
    int getWidth() const;
    virtual bool isPointInside(int x, int y);
    std::string getID();
    void setID(std::string newID);

protected:
    int x;
    int y;
    int mHeight;
    int mWidth;
    std::string mID;
};


#endif //OBJECT_H
