//
// Created by eal on 11/25/24.
//

#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <vector>
#include <EngineBase/DrawAble.h>

#include "DrawAbleController.h"

class Scene
{
public:
    Scene();

    void addDrawAbleToScene(const std::weak_ptr<DrawAble> &drawAble);

    void drawingDone();

    void updateDone();

    std::pair<int, int> getOffsetForDrawing();

    [[nodiscard]] std::vector<std::unique_ptr<DrawAble>> &getDrawables() const;

private:
    std::unique_ptr<DrawAbleController> drawAbleController_;
};


#endif //SCENE_H
