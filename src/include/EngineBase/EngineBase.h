//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef ENGINEBASE_H
#define ENGINEBASE_H

#include <functional>
#include <list>
#include <string>
#include <memory>


#include "Objects/DragAble.h"
#include "Objects/DrawAble.h"
#include "KeyBoardKeys.h"
#include "Objects/SpeedAble.h"


class EngineBase
{
public:
    static int loadTexture(const std::string &path);

    static void startGUI(const std::function<void(float deltaTime)> &update);

    static bool keyPressed(Key key);

    static bool keyReleased(Key key);

    static bool mouseButtonPressed(Button mouseButton);

    static bool mouseButtonReleased(Button mouseButton);

    static int addDrawAble();

    static int addSpeedAble();

    static int addDragAble();

    static void executeCommand(Command command);

private:
    static inline bool windowInitialized_ = false;

    static void initializeWindow();
};


#endif //ENGINEBASE_H
