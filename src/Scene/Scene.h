//
// Created by eal on 11/25/24.
//

#ifndef SCENE_H
#define SCENE_H
#include <memory>
#include <vector>
#include <EngineBase/DrawAble.h>

class Scene
{
public:
    Scene() = default;
    void addDrawAbleToScene(const std::weak_ptr<DrawAble>& drawAble);
    [[nodiscard]] std::vector<std::shared_ptr<DrawAble>> getDrawables() const;

private:
    std::vector<std::weak_ptr<DrawAble>> drawAbles_;
};


#endif //SCENE_H
