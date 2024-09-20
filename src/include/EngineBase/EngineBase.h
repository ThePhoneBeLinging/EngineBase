//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef ENGINEBASE_H
#define ENGINEBASE_H
#include <functional>
#include <string>


#include "DragAble.h"
#include "DrawAble.h"
#include "KeyBoardKeys.h"
#include "SpeedAble.h"


class EngineBase
{
public:
    static int loadTexture(const std::string& path);
    static void startGUI(const std::function<void(float deltaTime)>& update);

    static bool keyPressed(Key key);
    static bool keyReleased(Key key);
    static bool mouseButtonPressed(Button mouseButton);
    static bool mouseButtonReleased(Button mouseButton);
    static void addDrawAble(const std::weak_ptr<DrawAble>&);
    static void addSpeedAble(const std::weak_ptr<SpeedAble>&);
    static void addDragAble(const std::weak_ptr<DragAble>&);

private:
    static inline bool windowInitialized_ = false;
    static void initializeWindow();
};


#endif //ENGINEBASE_H
