//
// Created by eal on 10/31/24.
//

#include "UpdateController.h"
#include "EngineBase/EngineBase.h"

void UpdateController::beginUpdateLoop()
{
    while (not EngineBase::getGraphicsLibrary()->toCloseWindow())
    {
        std::unique_lock lock(mutex_);
        for (const auto& function : updateFunctionsToAdd_)
        {
            updateFunctions_.push_back(function);
        }
        updateFunctionsToAdd_.clear();
        lock.unlock();
        for (const auto& function : updateFunctions_)
        {
            //TODO Measure time since last update;
            function(0.003);
        }
    }
}

void UpdateController::registerUpdateFunction(const std::function<void(float deltaTime)>& updateFunction)
{
    std::lock_guard lock(mutex_);
    updateFunctionsToAdd_.push_back(updateFunction);
}
