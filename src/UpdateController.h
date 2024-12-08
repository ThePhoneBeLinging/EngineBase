//
// Created by eal on 10/31/24.
//

#ifndef UPDATECONTROLLER_H
#define UPDATECONTROLLER_H
#include <functional>
#include <memory>
#include <shared_mutex>
#include <GraphicsInterface/IGraphicsLibrary.h>
#include <Scene/SceneController.h>


class UpdateController
{
public:
    explicit UpdateController(const std::shared_ptr<IGraphicsLibrary>& graphicsLibrary, std::shared_ptr<SceneController>& sceneController);
    void startUpdateLoop();
    void registerUpdateFunction(const std::function<void(double deltaTime)>& updateFunction);
private:
    std::shared_ptr<IGraphicsLibrary> graphicsLibrary_;
    std::shared_ptr<SceneController>& sceneController_;
    std::mutex mutex_;
    std::vector<std::function<void(double deltaTime)>> updateFunctions_;
    std::vector<std::function<void(double deltaTime)>> updateFunctionsToAdd_;
    std::vector<std::chrono::time_point<std::chrono::high_resolution_clock>> updateTimePoints_;
};



#endif //UPDATECONTROLLER_H
