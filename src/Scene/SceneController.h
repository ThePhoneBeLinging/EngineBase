//
// Created by eal on 11/25/24.
//

#ifndef SCENECONTROLLER_H
#define SCENECONTROLLER_H
#include "GraphicsInterface/IGraphicsLibrary.h"
#include "Scene.h"


class SceneController
{
public:
    explicit SceneController(std::shared_ptr<IGraphicsLibrary> graphicsLibrary);
    void startDrawing() const;
    void drawingDone();
    void updateDone();
    std::shared_ptr<Scene> getScene(int scene);

private:
    std::vector<std::shared_ptr<Scene>> scenes_;
    std::shared_ptr<IGraphicsLibrary> graphicsInterface_;
};


#endif //SCENECONTROLLER_H
