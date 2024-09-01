//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H
#include "../Components/BaseFiles/Button.h"
#include <list>
#include <memory>
#include "Components/BaseFiles/ObjectFiles/ConnectionManager.h"
#include "Components/BaseFiles/ObjectFiles/DragAble.h"
#include "Components/BaseFiles/ObjectFiles/Object.h"
#include "Components/BaseFiles/ObjectFiles/SceneManager.h"
#include "Controllers/TextureController.h"
#include "Components/BaseFiles/ObjectFiles/TextureManager.h"
#include "Components/BaseFiles/ObjectFiles/Visibility.h"
#include "Components/BaseFiles/ObjectFiles/VelocityManager.h"


class DrawAbleObject : public Object
{
public:
    virtual ~DrawAbleObject() = default;
    DrawAbleObject(int x, int y, int height, int width);
    virtual void draw();
    virtual void deleteObject();
    virtual void addToScene(int scene);
    bool isPointInside(int x, int y) override;
    void setX(int x) override;
    void setY(int y) override;

    TextureManager mTextureManager;
    Visibility mVisibility;
    DragAble mDragAble;
    SceneManager mSceneManager;
    Button mButton;
    ConnectionManager mConnectionManager;
    CollisionManager mCollisionManager;
    VelocityManager mVelocityManager;
    std::mutex mPositionLock;
private:
    bool isCollidingWithCollidable();
};


#endif //DRAWABLEOBJECT_H
