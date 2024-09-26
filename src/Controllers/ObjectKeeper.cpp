//
// Created by Elias on 25/09/2024.
//

#include "ObjectKeeper.h"


int ObjectKeeper::addDrawAble()
{
    auto drawAble = std::make_shared<DrawAble>();
    std::unique_lock vectorLock(vectorResizeMutex);
    writeVector.load()->push_back(drawAble);
    drawAble->id(writeVector.load()->size() - 1);
    vectorLock.unlock();
    std::lock_guard lock(addedDrawAblesMutex);
    addedDrawAbles_.push_back(drawAble);
    switchVectors();
    return drawAble->id();
}

std::shared_ptr<DrawAble> ObjectKeeper::getDrawAbleForReading(int id)
{
    return (*readVector)[id];
}

std::shared_ptr<DrawAble> ObjectKeeper::getDrawAbleForWriting(int id)
{
    switchVectors();
    std::lock_guard lock(changedDrawAblesMutex);
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
    std::lock_guard lock(changedDrawAblesMutex);
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
    writeVector.load()->emplace_back(drawAble);
}

void ObjectKeeper::executeCommand(Command command)
{
    switch (command.primaryCmd_)
    {

        case PrimaryCMD::UPDATE:

            switch (command.objectType_)
            {

                case ObjectType::DRAWABLE:
                    switch (command.secondaryCmd_)
                    {
                        case SecondaryCMD::X:
                        {
                            auto drawAble = getDrawAbleForWriting(command.id_);
                            drawAble->x(command.value_);
                            break;
                        }
                        case SecondaryCMD::Y:
                            break;
                        case SecondaryCMD::Z:
                            break;
                        case SecondaryCMD::WIDTH:
                            break;
                        case SecondaryCMD::HEIGHT:
                            break;
                        case SecondaryCMD::TEXTUREINDEX:
                            break;
                        case SecondaryCMD::XSPEED:
                            break;
                        case SecondaryCMD::YSPEED:
                            break;
                        case SecondaryCMD::XTARGET:
                            break;
                        case SecondaryCMD::YTARGET:
                            break;
                    }
                case ObjectType::SPEEDABLE:
                    break;
                case ObjectType::COLLIDABLE:
                    break;
                case ObjectType::DRAGABLE:
                    break;
            }
            break;
        case PrimaryCMD::DELETE:
            //TODO Not yet implemented
            break;
    }
}
