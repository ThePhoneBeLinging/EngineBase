//
// Created by Elias Aggergaard Larsen on 30/07/2024.
//

#include "EngineBase/HotKeyManager.h"
#include "Controllers/ObjectController.h"

std::list<OnKeyPress *> HotKeyManager::mOnKeyPresses;
std::mutex HotKeyManager::mMutex;

void HotKeyManager::addOnKeyPress(int key, std::function<void()> function, ActivationMethod activationMethod)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mOnKeyPresses.push_back(new OnKeyPress(key, function, activationMethod));
}

void HotKeyManager::handleHotKeys()
{
    std::unique_lock<std::mutex> lock(mMutex);
    auto localOnKeyPresses = mOnKeyPresses;
    lock.unlock();
    for (auto onKeyPress: localOnKeyPresses) {
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
    std::lock_guard<std::mutex> lock(mMutex);
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
    std::lock_guard<std::mutex> lock(mMutex);
    mOnKeyPresses.push_back(new OnKeyPress(std::move(keys), std::move(function), activationMethod));
}


