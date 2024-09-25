//
// Created by Elias on 25/09/2024.
//

#include "ObjectKeeper.h"


std::weak_ptr<DrawAble> ObjectKeeper::addDrawAble()
{
    auto drawAble = std::make_shared<DrawAble>();
    appendToWriteVector(drawAble);
    switchVectors();
    return {drawAble};
}

std::weak_ptr<DrawAble> ObjectKeeper::getDrawAbleForReading(int id)
{
    return (*readVector)[id];
}

std::weak_ptr<DrawAble> ObjectKeeper::getDrawAbleForWriting(int id)
{
    std::shared_lock lock(vectorResizeMutex);
    switchVectors();
    changedDrawAbles_.push_back(id);
    return (*writeVector)[id];
}

void ObjectKeeper::switchVectors()
{
    std::unique_lock lock(vectorResizeMutex);
    auto temp = std::atomic_exchange(&readVector, writeVector.load());
    writeVector.store(temp);
    copyReadToWriteDrawAbles();
}

void ObjectKeeper::copyReadToWriteDrawAbles()
{
    for (auto changedDrawAble: changedDrawAbles_)
    {
        (*writeVector)[changedDrawAble] = std::make_shared<DrawAble>(*(*readVector)[changedDrawAble]);
    }
    for (const auto &addedDrawAble: addedDrawAbles_)
    {
        appendToWriteVector(std::make_shared<DrawAble>(*addedDrawAble));
    }
}

void ObjectKeeper::appendToWriteVector(const std::shared_ptr<DrawAble> &drawAble)
{
    std::unique_lock lock(vectorResizeMutex);
    writeVector.load()->emplace_back(drawAble);
    addedDrawAbles_.emplace_back(drawAble);
}
