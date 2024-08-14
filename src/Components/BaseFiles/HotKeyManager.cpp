//
// Created by Elias Aggergaard Larsen on 30/07/2024.
//

#include <iostream>
#include "EngineBase/HotKeyManager.h"
#include "Controllers/ObjectController.h"

std::list<OnKeyPress *> HotKeyManager::mOnKeyPresses;

void HotKeyManager::addOnKeyPress(int key, std::function<void()> function, ActivationMethod activationMethod)
{
    mOnKeyPresses.push_back(new OnKeyPress(key, function, activationMethod));
}

void HotKeyManager::handleHotKeys()
{
    for (auto onKeyPress: mOnKeyPresses) {
        if (onKeyPress->getActivationMethod() == TriggerOnce) {
            if (areAllNeededKeysDown(onKeyPress)) {
                if (!onKeyPress->hasActivatedFunction()) {
                    onKeyPress->executeFunction();
                }
            } else {
                onKeyPress->setHasActivatedFunction(false);
            }
        } else if (onKeyPress->getActivationMethod() == TriggerContinuously) {
            if (areAllNeededKeysDown(onKeyPress)) {
                onKeyPress->executeFunction();
            }
        }
    }
}

bool HotKeyManager::areAllNeededKeysDown(OnKeyPress *onKeyPress)
{
    for (int key: onKeyPress->getKeys()) {
        if (!ObjectController::isKeyDown(key)) {
            return false;
        }
    }
    return true;
}

void
HotKeyManager::addOnKeyPress(std::list<int> keys, std::function<void()> function, ActivationMethod activationMethod)
{
    mOnKeyPresses.push_back(new OnKeyPress(std::move(keys), std::move(function), activationMethod));
}


