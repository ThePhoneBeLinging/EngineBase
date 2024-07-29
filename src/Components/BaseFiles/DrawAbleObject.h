//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H
#include <Button.h>
#include <list>
#include <memory>

#include "ConnectionManager.h"
#include "DragAble.h"
#include "Object.h"
#include "SceneManager.h"
#include "TextureController.h"
#include "Visibility.h"


class DrawAbleObject : public Object
{
public:
    virtual ~DrawAbleObject() = default;
    DrawAbleObject(int x, int y, int height, int width);
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

    Visibility mVisibility;
    DragAble mDragAble;
    SceneManager mSceneManager;
    ConnectionManager mConnectionManager;
    Button mButton;

protected:
    int z;
    int mTextureIndex;
    int mTextureSecondIndex;
};


#endif //DRAWABLEOBJECT_H
