//
// Created by eal on 10/24/24.
//

#ifndef ENGINEBASE_H
#define ENGINEBASE_H
#include <functional>
#include <utility>

#include "UpdateController.h"
#include "GraphicsInterface/IGraphicsLibrary.h"


class EngineBase
{
public:
    EngineBase();
    void launch();
    void registerDrawAble(const std::shared_ptr<DrawAble>& drawAble);
    void registerUpdateFunction(const std::function<void(double deltaTime)>& updateFunction);
    std::shared_ptr<IGraphicsLibrary> getGraphicsLibrary();
    std::shared_ptr<UpdateController> getUpdateController();

private:
    std::shared_ptr<IGraphicsLibrary> graphicsInterface_;
    std::shared_ptr<UpdateController> updateController_;
    std::vector<std::weak_ptr<DrawAble>> drawAble_;
};


#endif //ENGINEBASE_H
