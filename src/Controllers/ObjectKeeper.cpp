//
// Created by Elias on 25/09/2024.
//

#include "ObjectKeeper.h"
#include "ObjectController.h"


int ObjectKeeper::addDrawAble()
{
    auto drawAble = std::make_shared<DrawAble>();
    std::unique_lock vectorLock(vectorResizeMutex);
    writeVector.load()->push_back(drawAble);
    drawAble->id(writeVector.load()->size() - 1);
    vectorLock.unlock();
    std::lock_guard lock(addedDrawAblesMutex);
    addedDrawAbles_.push_back(drawAble);
    return drawAble->id();
}

std::shared_ptr<DrawAble> ObjectKeeper::getDrawAbleForReading(int id)
{
    return (*readVector)[id];
}

std::shared_ptr<DrawAble> ObjectKeeper::getDrawAbleForWriting(int id)
{
    std::lock_guard lock(changedDrawAblesMutex);
    std::lock_guard addedDrawAblesLock(addedDrawAblesMutex);
    changedDrawAbles_.push_back(id);
    return (*writeVector)[id];
}

void ObjectKeeper::switchVectors()
{
    std::lock_guard lock(vectorResizeMutex);
    auto temp = std::atomic_exchange(&readVector, writeVector.load());
    writeVector.store(temp);
    copyReadToWriteDrawAbles();
}

void ObjectKeeper::copyReadToWriteDrawAbles()
{
    std::lock_guard addedLock(addedDrawAblesMutex);
    for (const auto& addedDrawAble : addedDrawAbles_)
    {
        appendToWriteVector(std::make_shared<DrawAble>(*addedDrawAble));
    }
    addedDrawAbles_.clear();
    std::lock_guard changeLock(changedDrawAblesMutex);
    for (auto changedDrawAble : changedDrawAbles_)
    {
        (*writeVector)[changedDrawAble] = (*readVector)[changedDrawAble];
    }
    changedDrawAbles_.clear();
}

void ObjectKeeper::appendToWriteVector(const std::shared_ptr<DrawAble>& drawAble)
{
    writeVector.load()->emplace_back(drawAble);
}

void ObjectKeeper::executeCommand(Command command)
{
    switch (command.primaryCmd_)
    {
    case PrimaryCMD::UPDATE:
        {
            switch (command.objectType_)
            {
            case ObjectType::DRAWABLE:
                {
                    switch (command.secondaryCmd_)
                    {
                    case SecondaryCMD::X:
                        {
                            auto drawAble = getDrawAbleForWriting(command.id_);
                            drawAble->x(command.value_);
                            break;
                        }
                    case SecondaryCMD::Y:
                        {
                            auto drawAble = getDrawAbleForWriting(command.id_);
                            drawAble->y(command.value_);
                            break;
                        }
                    case SecondaryCMD::Z:
                        {
                            auto drawAble = getDrawAbleForWriting(command.id_);
                            drawAble->z(static_cast<int>(command.value_));
                            break;
                        }
                    case SecondaryCMD::WIDTH:
                        {
                            auto drawAble = getDrawAbleForWriting(command.id_);
                            drawAble->width(static_cast<int>(command.value_));
                            break;
                        }
                    case SecondaryCMD::HEIGHT:
                        {
                            auto drawAble = getDrawAbleForWriting(command.id_);
                            drawAble->height(static_cast<int>(command.value_));
                            break;
                        }
                    case SecondaryCMD::TEXTUREINDEX:
                        {
                            auto drawAble = getDrawAbleForWriting(command.id_);
                            drawAble->textureIndex(static_cast<int>(command.value_));
                            break;
                        }
                    default:
                        {
                            throw std::invalid_argument("Invalid secondary command");
                        }
                    }
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
        }
    case PrimaryCMD::DELETE:
        //TODO Not yet implemented
        break;
    case PrimaryCMD::DONEWRITING:
        {
            doneWriting();
            break;
        }
    case PrimaryCMD::SORTDRAWABLES:
        {
            ObjectController::sortDrawAbles();
            break;
        }
    }
}

void ObjectKeeper::doneWriting()
{
    switchVectors();
}
