//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef ENGINEBASE_H
#define ENGINEBASE_H

#include <functional>
#include <list>
#include <string>
#include <memory>
#include "Objects/DrawAble.h"
#include "KeyBoardKeys.h"
#include "EngineBase/Command.h"
#include <Controllers/ObjectKeeper.h>
#include "Controllers/ObjectController.h"
#include "Controllers/TextureController.h"
#include <thread>

class EngineBase
{
public:
    static int loadTexture(const std::string& path);

    static void startGUI(const std::function<void(float deltaTime)>& externalUpdateFunction);

    static bool keyPressed(Key key);

    static bool keyReleased(Key key);

    static bool mouseButtonPressed(Button mouseButton);

    static bool mouseButtonReleased(Button mouseButton);

    static int addDrawAble();

    static std::shared_ptr<DrawAble> getDrawAble(int id);

    static void doneWriting();

    static void executeCommand(Command command);

    static std::pair<int, int> getMousePosition();

private:
    static inline bool windowInitialized_ = false;

    static void initializeWindow();

    static void updateFunction(const std::function<void(float deltaTime)>&);
};


#endif //ENGINEBASE_H
