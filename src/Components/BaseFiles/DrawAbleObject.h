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
    virtual void addToScene(int scene);
    virtual void removeFromScene();


    void setX(int x);
    void setY(int y);
    int getZ() const;
    void setZ(int z);
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
    virtual void setScene(int scene);
    bool isDragAble() const;
    void setDragAble(bool dragAble);

protected:
    int x;
    int y;
    int z;
    int mTextureIndex;
    int mTextureSecondIndex;
    int mHeight;
    int mWidth;
    bool mIsVisible;
    bool mIsDragAble;
    std::shared_ptr<TextureController> mTextureController;
    int mScene;
};


#endif //DRAWABLEOBJECT_H
