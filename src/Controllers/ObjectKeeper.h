//
// Created by Elias on 25/09/2024.
//

#ifndef SAMPLEPROJECT_OBJECTKEEPER_H
#define SAMPLEPROJECT_OBJECTKEEPER_H

#include <string>
#include <memory>
#include <vector>
#include <shared_mutex>
#include <atomic>
#include <EngineBase/Command.h>
#include "Objects/DrawAble.h"

class ObjectKeeper
{
public:
    static int addDrawAble();

    static std::shared_ptr<DrawAble> getDrawAbleForReading(int id);

    static std::shared_ptr<DrawAble> getDrawAbleForWriting(int id);

    static void executeCommand(Command command);

    static void doneWriting();

private:
    static void switchVectors();

    static void copyReadToWriteDrawAbles();

    static void appendToWriteVector(const std::shared_ptr<DrawAble>& drawAble);

    static inline std::atomic_bool shouldSwitch = false;
    static inline std::shared_mutex vectorResizeMutex;
    static inline std::vector<std::shared_ptr<DrawAble>> drawAbles_;
    static inline std::vector<std::shared_ptr<DrawAble>> otherDrawAbles_;
    static inline std::atomic<std::vector<std::shared_ptr<DrawAble>>*> readVector = &drawAbles_;
    static inline std::atomic<std::vector<std::shared_ptr<DrawAble>>*> writeVector = &otherDrawAbles_;
    static inline std::vector<int> changedDrawAbles_;
    static inline std::vector<std::shared_ptr<DrawAble>> addedDrawAbles_;
    static inline std::mutex addedDrawAblesMutex;
    static inline std::mutex changedDrawAblesMutex;
};


#endif //SAMPLEPROJECT_OBJECTKEEPER_H
