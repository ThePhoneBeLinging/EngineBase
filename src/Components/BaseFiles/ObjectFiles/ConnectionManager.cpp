//
// Created by Elias Aggergaard Larsen on 28/07/2024.
//

#include "ConnectionManager.h"

#include <ObjectController.h>


void ConnectionManager::connectDrawAble(DrawAbleObject* drawAble)
{
    this->mConnectedObjects.push_back(drawAble);
    this->sortList();
}

void ConnectionManager::disconnectDrawAble(DrawAbleObject* drawAble)
{
    this->mConnectedObjects.remove(drawAble);
    ObjectController::addDrawAbleObject(drawAble);
}

std::list<DrawAbleObject*> ConnectionManager::getConnectedObjects()
{
    return mConnectedObjects;
}

void ConnectionManager::sortList()
{
    mConnectedObjects.sort([](const DrawAbleObject* a, const DrawAbleObject* b)
    {
        return a->mTextureManager.getZ() < b->mTextureManager.getZ();
    });
}
