//
// Created by Elias Aggergaard Larsen on 17/08/2024.
//

#include "CollisionManager.h"

CollisionManager::CollisionManager()
{
}

CollisionMode CollisionManager::getCollisionMode()
{
    return mCollisionMode;
}

void CollisionManager::setCollisionMode(CollisionMode collisionMode)
{
    mCollisionMode = collisionMode;
}

void CollisionManager::setCollidingObjects(std::list<DrawAbleObject*> collidingObjects)
{
    mCollidingObjects = collidingObjects;
}

void CollisionManager::addCollidingObject(DrawAbleObject* drawAble)
{
    mCollidingObjects.push_back(drawAble);
}

std::list<DrawAbleObject*>& CollisionManager::getCollidingObjects()
{
    return mCollidingObjects;
}
