//
// Created by Elias Aggergaard Larsen on 30/07/2024.
//

#include <iostream>
#include "HotKeyManager.h"
#include "ObjectController.h"

std::list<OnKeyPress*> HotKeyManager::mOnKeyPresses;

void HotKeyManager::addOnKeyPress(OnKeyPress *onKeyPress)
{
    mOnKeyPresses.push_back(onKeyPress);
}

void HotKeyManager::handleHotKeys()
{
    for (auto onKeyPress : mOnKeyPresses)
    {
        if (onKeyPress->getActivationMethod() == TriggerOnce)
        {
            bool areKeysPressed = true;
            for (int key : onKeyPress->getKeys())
            {
                if (!ObjectController::isKeyDown(key))
                {
                    areKeysPressed = false;
                    onKeyPress->setHasActivatedFunction(false);
                    break;
                }
            }
            if (!onKeyPress->hasActivatedFunction() && areKeysPressed)
            {
                onKeyPress->executeFunction();
            }
        }
    }
}
