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
    virtual ~DrawAbleObject() = default;
    DrawAbleObject(int x, int y, int height, int width, const std::shared_ptr<TextureController>& textureController);
    void draw();
    virtual void deleteObject();


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
    int getScene() const;
    void setScene(int m_scene);
    int getLayer() const;
    void setLayer(int m_layer);

protected:
    int x;
    int y;
    int mTextureIndex;
    int mTextureSecondIndex;
    int mHeight;
    int mWidth;
    bool mIsVisible;
    std::shared_ptr<TextureController> mTextureController;
    int mScene;
    int mLayer;
};


#endif //DRAWABLEOBJECT_H
