//
// Created by Elias Aggergaard Larsen on 08/12/2024.
//

#ifndef DRAWABLECONTROLLER_H
#define DRAWABLECONTROLLER_H
#include <memory>
#include <vector>
#include <EngineBase/DrawAble.h>


class DrawAbleController
{
public:
    DrawAbleController();
    void addDrawAble(const std::weak_ptr<DrawAble>& drawAble);
    void updateLoopDone();
    void drawingLoopDone();
    std::vector<std::shared_ptr<DrawAble>>& getDrawAbles();

private:
    int activeDrawingIndex_;
    int nextDrawingIndex_;
    int updatingIndex_;
    std::vector<std::vector<std::shared_ptr<DrawAble>>> sharedDrawAbles_;
    std::vector<std::weak_ptr<DrawAble>> weakDrawAbles_;
};



#endif //DRAWABLECONTROLLER_H
