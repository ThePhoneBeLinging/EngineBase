//
// Created by eal on 10/30/24.
//

#ifndef RAYLIBIMPLEMENTATION_H
#define RAYLIBIMPLEMENTATION_H
#include <utility>
#include <vector>

#include "IGraphicsLibrary.h"
#include "raylib.h"


class RayLibImplementation : public IGraphicsLibrary
{
public:
    RayLibImplementation() = default;
    void init() override;
    std::pair<int, int> getMousePos() override;
    void draw(std::shared_ptr<DrawAble> drawAble) override;
    int loadTexture(const std::string& texturePath) override;
    std::pair<int, int> getWindowSize() override;
    bool toCloseWindow() override;

private:
    std::vector<Texture2D> textures;
};


#endif //RAYLIBIMPLEMENTATION_H
