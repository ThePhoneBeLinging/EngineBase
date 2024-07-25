//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H
#include <memory>

#include "TextureController.h"


class DrawAbleObject
{
public:
    DrawAbleObject(int x, int y, int height, int width, const std::shared_ptr<TextureController>& textureController);
    void draw();
    void setX(int x);
    void setY(int y);
    void setTextureIndex(int textureIndex);
    void setTextureSecondIndex(int secondIndex);
    void setHeight(int height);
    void setWidth(int width);
    void setVisible(bool isVisible);
    int getX() const;
    int getY() const;
    int getTextureIndex() const;
    int getSecondTextureIndex() const;
    int getHeight() const;
    int getWidth() const;
    bool isVisible() const;

private:
    int x;
    int y;
    int mTextureIndex;
    int mTextureSecondIndex;
    int mHeight;
    int mWidth;
    bool mIsVisible;
    std::shared_ptr<TextureController> mTextureController;
};


#endif //DRAWABLEOBJECT_H
