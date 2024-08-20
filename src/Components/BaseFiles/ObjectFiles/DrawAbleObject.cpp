//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include "EngineBase/DrawAbleObject.h"

#include "Controllers/ObjectController.h"
#include "Controllers/TextureController.h"
#include "EngineBase/EngineBase.h"

DrawAbleObject::DrawAbleObject(int x, int y, int height, int width) :
    Object(
        x, y, height, width), mTextureManager(), mVisibility(), mDragAble(), mSceneManager(), mButton(), mConnectionManager(), mCollisionManager(), mVelocityManager(this)
{
    this->x = x;
    this->y = y;
    this->mHeight = height;
    this->mWidth = width;
    this->mTextureManager = TextureManager();
    this->mTextureManager.setDrawAble(this);
    this->mVisibility = Visibility();
    this->mDragAble = DragAble();
    this->mSceneManager = SceneManager();
    this->mButton = Button();
    mButton.setDrawAbleObject(this);
    this->mConnectionManager = ConnectionManager();
    mConnectionManager.connectDrawAble(this);
    this->mCollisionManager = CollisionManager();
    this->mVelocityManager = VelocityManager(this);
}

void DrawAbleObject::draw()
{
    std::lock_guard<std::mutex> lock(mPositionLock);
    for (auto drawAble : mConnectionManager.getConnectedObjects())
    {
        if (drawAble->mVisibility.isVisisble())
        {
            TextureController::draw(this);
        }
        drawAble->mTextureManager.advanceAnimation();
    }
}

void DrawAbleObject::deleteObject()
{
    ObjectController::removeObject(this);
}

void DrawAbleObject::addToScene(int scene)
{
    this->mSceneManager.setScene(scene);
    ObjectController::addDrawAbleObject(this);
}

void DrawAbleObject::removeFromScene()
{
    ObjectController::removeObject(this);
}

bool DrawAbleObject::isPointInside(int x, int y)
{
    if (Object::isPointInside(x, y)) return true;
    for (auto connectedTexture : this->mConnectionManager.getConnectedObjects())
    {
        if (connectedTexture == this) continue;
        if (connectedTexture->isPointInside(x, y))
        {
            return true;
        }
    }
    return false;
}

void DrawAbleObject::setX(int x)
{
    std::lock_guard<std::mutex> lock(mPositionLock);
    int oldX = this->x;
    Object::setX(x);
    if (mCollisionManager.getCollisionMode() == Collide)
    {
        mCollisionManager.setCollidingObjects(ObjectController::getCollidingDrawAbles(this));
        if (isCollidingWithCollidable())
        {
            this->x = oldX;
            mCollisionManager.setCollidingObjects(ObjectController::getCollidingDrawAbles(this));
        }
    }
}

void DrawAbleObject::setY(int y)
{
    std::lock_guard<std::mutex> lock(mPositionLock);
    int oldY = this->y;
    Object::setY(y);
    if (mCollisionManager.getCollisionMode() == Collide)
    {
        mCollisionManager.setCollidingObjects(ObjectController::getCollidingDrawAbles(this));
        if (isCollidingWithCollidable())
        {
            this->y = oldY;
            mCollisionManager.setCollidingObjects(ObjectController::getCollidingDrawAbles(this));
        }
    }
}

bool DrawAbleObject::isCollidingWithCollidable()
{
    for (auto object : mCollisionManager.getCollidingObjects())
    {
        if (object->mCollisionManager.getCollisionMode() == Collide)
        {
            return true;
        }
    }
    return false;
}





