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

    void addDrawAble(const std::weak_ptr<DrawAble> &drawAble);

    void updateLoopDone();

    void drawingLoopDone();

    void setOffset(int offsetX, int offsetY);

    void updateOffset(int deltaOffsetX, int deltaOffsetY);

    std::pair<int, int> getOffsetForDrawing();

    std::vector<std::unique_ptr<DrawAble>> &getDrawAbles();

private:
    bool isDrawAbleOnScreen(const std::shared_ptr<DrawAble> &drawAble);

    std::mutex mutex_;
    int activeDrawingIndex_;
    int nextDrawingIndex_;
    int updatingIndex_;
    std::pair<int, int> updateOffset_;
    std::vector<std::pair<int, int>> offsets_;
    std::vector<std::vector<std::unique_ptr<DrawAble>>> sharedDrawAbles_;
    std::vector<std::weak_ptr<DrawAble>> weakDrawAbles_;
};


#endif //DRAWABLECONTROLLER_H
