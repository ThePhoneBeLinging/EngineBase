//
// Created by eal on 10/24/24.
//

#include "EngineBase/EngineBase.h"
#include <thread>
#include "GraphicsInterface/RayLibImplementation.h"

EngineBase::EngineBase()
{
    graphicsInterface_ = std::make_shared<RayLibImplementation>();
}

void EngineBase::launch()
{
    while (not graphicsInterface_->toCloseWindow())
    {
        std::unique_lock lock(drawAbleMutex_);
        std::vector<std::shared_ptr<DrawAble>> drawables;
        std::vector<std::shared_ptr<Text>> texts;
        std::vector<std::weak_ptr<DrawAble>> expiredDrawAbles;
        for (const auto& drawAble : drawAbles_)
        {
            drawables.push_back(drawAble.lock());
        }
        lock.unlock();
        std::unique_lock guard(textsMutex_);

        for (const auto& text : texts_)
        {
            texts.push_back(text.lock());
        }
        guard.unlock();
        graphicsInterface_->draw(drawables,texts);
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
    }
    graphicsInterface_->closeWindow();
}

void EngineBase::registerDrawAble(const std::shared_ptr<DrawAble>& drawAble)
{
    std::lock_guard guard(drawAbleMutex_);
    drawAbles_.push_back(drawAble->getDrawAblePtr());
}

void EngineBase::registerText(const std::shared_ptr<Text>& text)
{
    std::lock_guard guard(textsMutex_);
    texts_.push_back(text);
}

std::shared_ptr<IGraphicsLibrary> EngineBase::getGraphicsLibrary()
{
    return graphicsInterface_;
}