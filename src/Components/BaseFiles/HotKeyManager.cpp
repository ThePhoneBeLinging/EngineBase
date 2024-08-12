//
// Created by Elias Aggergaard Larsen on 30/07/2024.
//

#include <iostream>
#include "HotKeyManager.h"
#include "Controllers/ObjectController.h"

std::list<OnKeyPress*> HotKeyManager::mOnKeyPresses;

void HotKeyManager::addOnKeyPress(OnKeyPress* onKeyPress)
{
    mOnKeyPresses.push_back(onKeyPress);
}

void HotKeyManager::handleHotKeys()
{
    for (auto onKeyPress : mOnKeyPresses)
    {
        if (onKeyPress->getActivationMethod() == TriggerOnce)
        {
            if (areAllNeededKeysDown(onKeyPress))
            {
                if (!onKeyPress->hasActivatedFunction())
                {
                    onKeyPress->executeFunction();
                }
            }
            else
            {
                onKeyPress->setHasActivatedFunction(false);
            }
        }
        else if (onKeyPress->getActivationMethod() == TriggerContinuously)
        {
            if (areAllNeededKeysDown(onKeyPress))
            {
                onKeyPress->executeFunction();
            }
        }
    }
}

bool HotKeyManager::areAllNeededKeysDown(OnKeyPress* onKeyPress)
{
    for (int key : onKeyPress->getKeys())
    {
        if (!ObjectController::isKeyDown(key))
        {
            return false;
        }
    }
    return true;
}


