//
// Created by eal on 11/25/24.
//

#ifndef SCENECONTROLLER_H
#define SCENECONTROLLER_H

#include "GraphicsInterface/IGraphicsLibrary.h"
#include "DrawAbleController.h"


class SceneController
{
public:
    explicit SceneController(std::shared_ptr<IGraphicsLibrary> graphicsLibrary);

    void startDrawing() const;

    void updateDone(double deltaTime);

    std::shared_ptr<DrawAbleController>& getCurrentDrawAbleController();

private:
    std::vector<std::shared_ptr<DrawAbleController>> drawAbleControllers_;
    std::shared_ptr<IGraphicsLibrary> graphicsInterface_;
    double currentDeltaTime_;
    int updates_;
    std::atomic<double> updatesLastSecond_;
};


#endif //SCENECONTROLLER_H
