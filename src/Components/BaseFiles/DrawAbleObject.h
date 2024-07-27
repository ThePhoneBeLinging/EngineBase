//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H
#include <list>
#include <memory>

#include "DragAble.h"
#include "Object.h"
#include "TextureController.h"
#include "Visibility.h"


class DrawAbleObject : public Object
{
public:
    virtual ~DrawAbleObject() = default;
    DrawAbleObject(int x, int y, int height, int width, const std::shared_ptr<TextureController>& textureController);
    void draw();
    virtual void deleteObject();
    virtual void addToScene(int scene);
    virtual void removeFromScene();


    int getZ() const;
    void setZ(int z);
    void setTextureIndex(int textureIndex);
    void setTextureSecondIndex(int secondIndex);
    int getTextureIndex() const;
    int getSecondTextureIndex() const;
    int getScene() const;
    virtual void setScene(int scene);
    Visibility mVisibility;
    DragAble mDragAble;

protected:
    int z;
    int mTextureIndex;
    int mTextureSecondIndex;
    std::shared_ptr<TextureController> mTextureController;


    int mScene;
    std::list<DrawAbleObject*> connectedObjects;
};


#endif //DRAWABLEOBJECT_H
