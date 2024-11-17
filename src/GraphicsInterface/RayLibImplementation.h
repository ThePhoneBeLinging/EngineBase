//
// Created by eal on 10/30/24.
//

#ifndef RAYLIBIMPLEMENTATION_H
#define RAYLIBIMPLEMENTATION_H
#include <list>
#include <vector>

#include "IGraphicsLibrary.h"
#include "raylib.h"

class RayLibImplementation : public IGraphicsLibrary
{
public:
    RayLibImplementation();
    void addDrawAble(std::shared_ptr<DrawAble> drawAble) override;
    std::pair<int, int> getMousePos() override;
    void draw(std::shared_ptr<DrawAble> drawAble) override;
    int loadTexture(const std::string& texturePath) override;
    std::pair<int, int> getWindowSize() override;
    bool toCloseWindow() override;
    void startWindow() override;
    bool isKeyPressed(Key key) override;
    bool isKeyDown(Key key) override;
    bool isKeyReleased(Key key) override;
    bool isMouseButtonDown(Button button) override;
    bool isMouseButtonReleased(Button button) override;
    bool isMouseButtonPressed(Button button) override;

private:
    void drawFunction();
    std::vector<std::unique_ptr<Texture2D>> textures_;
    std::list<std::shared_ptr<DrawAble>> drawAbles_;
};


#endif //RAYLIBIMPLEMENTATION_H
