//
// Created by Elias Aggergaard Larsen on 30/07/2024.
//

#ifndef HOTKEYMANAGER_H
#define HOTKEYMANAGER_H

#include <vector>
#include "EngineBase/OnKeyPress.h"


class HotKeyManager
{
public:
    static void addOnKeyPress(OnKeyPress* onKeyPress);
    static void handleHotKeys();
    static bool areAllNeededKeysDown(OnKeyPress* onKeyPress);

private:
    static std::list<OnKeyPress*> mOnKeyPresses;
};


#endif //HOTKEYMANAGER_H
