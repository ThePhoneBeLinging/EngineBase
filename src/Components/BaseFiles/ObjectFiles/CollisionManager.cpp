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
