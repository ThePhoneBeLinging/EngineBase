//
// Created by Elias on 25/09/2024.
//

#ifndef SAMPLEPROJECT_COMMANDHANDLER_H
#define SAMPLEPROJECT_COMMANDHANDLER_H


#include <string>
#include <memory>
#include <vector>
#include <shared_mutex>
#include <EngineBase/DragAble.h>
#include <EngineBase/SpeedAble.h>
#include <EngineBase/ClickAble.h>
#include "EngineBase/DrawAble.h"

class CommandHandler
{
public:
    static void handleCommand(std::string command);

    static std::weak_ptr<DrawAble> addDrawAble();

    static std::weak_ptr<SpeedAble> addSpeedAble();

    static std::weak_ptr<ClickAble> addClickAble();

    static std::weak_ptr<DrawAble> getDrawAble(int id);

    static std::weak_ptr<SpeedAble> getSpeedAble(int id);

    static std::weak_ptr<ClickAble> getClickAble(int id);

private:
    static inline std::shared_mutex drawAbleMutex_;
    static inline std::shared_mutex dragAbleMutex_;
    static inline std::shared_mutex speedAbleMutex_;
    static inline std::shared_mutex clickAbleMutex_;

    static inline std::vector<std::shared_ptr<DrawAble>> drawAbles_;
    static inline std::vector<std::shared_ptr<DragAble>> dragAbles_;
    static inline std::vector<std::shared_ptr<SpeedAble>> speedAbles_;
    static inline std::vector<std::shared_ptr<ClickAble>> clickAbles_;
};


#endif //SAMPLEPROJECT_COMMANDHANDLER_H
