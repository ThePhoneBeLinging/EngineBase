//
// Created by Elias Aggergaard Larsen on 08/12/2024.
//

#ifndef DRAWABLECONTROLLER_H
#define DRAWABLECONTROLLER_H

#include <atomic>
#include <memory>
#include <vector>
#include <EngineBase/DrawAble.h>


class DrawAbleController
{
public:
    DrawAbleController();

    void addDrawAble(const std::weak_ptr<DrawAble>& drawAble);

    void updateLoopDone(std::pair<int, int> windowSize);

    void drawingLoopDone();

    void setOffset(double offsetX, double offsetY);

    void updateOffset(double deltaOffsetX, double deltaOffsetY);

    std::pair<int, int> getOffsetForDrawing();

    std::pair<double, double> getCurrentUpdateOffset();

    std::vector<std::unique_ptr<DrawAble>>& getDrawAbles();

private:
    bool isDrawAbleOnScreen(const std::shared_ptr<DrawAble>& drawAble, int screenWidth, int screenHeight);
    std::mutex mutex_;
    int activeDrawingIndex_;
    int nextDrawingIndex_;
    int updatingIndex_;
    std::pair<double, double> updateOffset_;
    std::vector<std::pair<int, int>> offsets_;
    std::vector<std::vector<std::unique_ptr<DrawAble>>> sharedDrawAbles_;
    std::vector<std::weak_ptr<DrawAble>> weakDrawAbles_;
};


#endif //DRAWABLECONTROLLER_H
