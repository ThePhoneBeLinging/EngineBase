//
// Created by eal on 10/31/24.
//

#include "UpdateController.h"

#include <functional>

#include "EngineBase/EngineBase.h"

void UpdateController::beginUpdateLoop()
{
    for (auto& timePoint : updateTimePoints_)
    {
        timePoint = std::chrono::high_resolution_clock::now();
    }

    while (not EngineBase::getGraphicsLibrary()->toCloseWindow())
    {
        std::unique_lock lock(mutex_);
        for (const auto& function : updateFunctionsToAdd_)
        {
            updateFunctions_.push_back(function);
            updateTimePoints_.push_back(std::chrono::high_resolution_clock::now());
        }

        updateFunctionsToAdd_.clear();
        lock.unlock();
        for (int i = 0; i < updateTimePoints_.size(); i++)
        {
            updateFunctions_[i](std::chrono::duration<double>(updateTimePoints_[i] - std::chrono::high_resolution_clock::now()).count());
            updateTimePoints_[i] = std::chrono::high_resolution_clock::now();
        }
    }
}

void UpdateController::registerUpdateFunction(const std::function<void(double deltaTime)>& updateFunction)
{
    std::lock_guard lock(mutex_);
    updateFunctionsToAdd_.push_back(updateFunction);
}
