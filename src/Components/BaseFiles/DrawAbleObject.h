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
#include "TextureManager.h"
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
    bool isPointInside(int x, int y) override;


    TextureManager mTextureManager;
    Visibility mVisibility;
    DragAble mDragAble;
    SceneManager mSceneManager;
    ConnectionManager mConnectionManager;
    Button mButton;
};


#endif //DRAWABLEOBJECT_H
