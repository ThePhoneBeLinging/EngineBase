//
// Created by eal on 10/24/24.
//

#ifndef ENGINEBASE_H
#define ENGINEBASE_H
#include <functional>

#include "Text.h"
#include "GraphicsInterface/IGraphicsLibrary.h"


class EngineBase
{
public:
    EngineBase();
    void launch();
    void registerDrawAble(const std::shared_ptr<DrawAble>& drawAble);
    void registerText(const std::shared_ptr<Text>& text);
    std::shared_ptr<IGraphicsLibrary> getGraphicsLibrary();

private:
    std::mutex drawAbleMutex_;
    std::mutex textsMutex_;
    std::shared_ptr<IGraphicsLibrary> graphicsInterface_;
    std::vector<std::weak_ptr<DrawAble>> drawAbles_;
    std::vector<std::weak_ptr<Text>> texts_;
};


#endif //ENGINEBASE_H
