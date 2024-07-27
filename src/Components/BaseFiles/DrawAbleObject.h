//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H
#include <memory>

#include "Object.h"
#include "TextureController.h"


class DrawAbleObject : public Object
{
public:
    virtual ~DrawAbleObject() = default;
    DrawAbleObject(int x, int y, int height, int width, const std::shared_ptr<TextureController>& textureController);
    void draw();
    virtual void deleteObject();
    virtual void addToScene(int scene);
    virtual void removeFromScene();
    virtual bool isPointInside(int x, int y) = 0;


    int getZ() const;
    void setZ(int z);
    void setTextureIndex(int textureIndex);
    void setTextureSecondIndex(int secondIndex);
    void setVisible(bool isVisible);
    int getTextureIndex() const;
    int getSecondTextureIndex() const;
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
