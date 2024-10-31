//
// Created by eal on 10/24/24.
//

#ifndef IGRAPHICSLIBRARY_H
#define IGRAPHICSLIBRARY_H
#include <functional>
#include <memory>

#include "EngineBase/DrawAble.h"

class IGraphicsLibrary
{
public:
    virtual ~IGraphicsLibrary() = default;
    virtual void init() = 0;
    virtual std::pair<int, int> getMousePos() = 0;
    virtual void draw(std::shared_ptr<DrawAble> drawAble) = 0;
    virtual int loadTexture(const std::string& texturePath) = 0;
    virtual std::pair<int, int> getWindowSize() = 0;
    virtual bool toCloseWindow() = 0;
    virtual void startWindow(std::function<void(float deltaTime)> updateFunction) = 0;
};
#endif //IGRAPHICSLIBRARY_H
