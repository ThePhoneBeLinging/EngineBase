//
// Created by Elias Aggergaard Larsen on 30/07/2024.
//

#ifndef HOTKEYMANAGER_H
#define HOTKEYMANAGER_H

#include <vector>
#include <mutex>
#include "Components/BaseFiles/OnKeyPress.h"


class HotKeyManager {
public:
    static void addOnKeyPress(int key, std::function<void()> function, ActivationMethod activationMethod);

    static void addOnKeyPress(std::list<int> keys, std::function<void()> function, ActivationMethod activationMethod);

    static void handleHotKeys();

    static bool areAllNeededKeysDown(OnKeyPress *onKeyPress);

private:
    static std::list<OnKeyPress *> mOnKeyPresses;
    static std::mutex mMutex;
};


#endif //HOTKEYMANAGER_H
