//
// Created by eal on 10/30/24.
//

#ifndef RAYLIBIMPLEMENTATION_H
#define RAYLIBIMPLEMENTATION_H

#include <list>
#include <unordered_map>
#include <vector>

#include "IGraphicsLibrary.h"
#include "raylib.h"

class RayLibImplementation : public IGraphicsLibrary
{
public:
  RayLibImplementation();

  std::pair<int, int> getMousePos() override;

  void draw(const std::vector<std::unique_ptr<DrawAble>>& drawAbles, int offsetX, int offsetY,
            double updatesLastSecond) override;

  void loadTexture(const std::string& texturePath) override;

  std::pair<int, int> getWindowSize() override;

  bool toCloseWindow() override;

  void closeWindow() override;

  bool isKeyPressed(Key key) override;

  bool isKeyDown(Key key) override;

  bool isKeyReleased(Key key) override;

  bool isMouseButtonDown(Button button) override;

  bool isMouseButtonReleased(Button button) override;

  bool isMouseButtonPressed(Button button) override;

  void setTargetFPS(int targetFPS) override;

private:
  std::unordered_map<std::string, Texture2D> textureMap_;
};


#endif //RAYLIBIMPLEMENTATION_H
