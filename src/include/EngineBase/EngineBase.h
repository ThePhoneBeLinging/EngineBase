//
// Created by eal on 10/24/24.
//

#ifndef ENGINEBASE_H
#define ENGINEBASE_H

#include <functional>

#include "Scene/SceneController.h"
#include "UpdateController.h"
#include "GraphicsInterface/IGraphicsLibrary.h"


class EngineBase
{
public:
    EngineBase();

    void launch() const;

    void registerDrawAble(const std::shared_ptr<DrawAble> &drawAble);

    void registerUpdateFunction(const std::function<void(double deltaTime)> &updateFunction) const;

    std::shared_ptr<IGraphicsLibrary> getGraphicsLibrary();

    std::shared_ptr<SceneController> getSceneController();

private:
    std::mutex mutex_;
    std::shared_ptr<IGraphicsLibrary> graphicsInterface_;
    std::unique_ptr<UpdateController> updateController_;
    std::shared_ptr<SceneController> sceneController_;
};


#endif //ENGINEBASE_H
