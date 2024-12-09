//
// Created by eal on 10/24/24.
//

#ifndef IGRAPHICSLIBRARY_H
#define IGRAPHICSLIBRARY_H
#include <memory>

class Scene;
#include "EngineBase/DrawAble.h"
#include "EngineBase/KeyBoardKeys.h"
#include <vector>

class IGraphicsLibrary
{
public:
    virtual ~IGraphicsLibrary() = default;
    virtual std::pair<int, int> getMousePos() = 0;
    virtual void draw(const std::vector<std::unique_ptr<DrawAble>>& drawAbles) = 0;
    virtual void loadTexture(const std::string& texturePath) = 0;
    virtual std::pair<int, int> getWindowSize() = 0;
    virtual bool toCloseWindow() = 0;
    virtual void closeWindow() = 0;
    virtual bool isKeyPressed(Key key) = 0;
    virtual bool isKeyDown(Key key) = 0;
    virtual bool isKeyReleased(Key key) = 0;
    virtual bool isMouseButtonDown(Button button) = 0;
    virtual bool isMouseButtonReleased(Button button) = 0;
    virtual bool isMouseButtonPressed(Button button) = 0;
};
#endif //IGRAPHICSLIBRARY_H
