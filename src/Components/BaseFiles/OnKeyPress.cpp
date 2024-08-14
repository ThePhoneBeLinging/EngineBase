//
// Created by Elias Aggergaard Larsen on 30/07/2024.
//

#include "OnKeyPress.h"
#include "EngineBase/HotKeyManager.h"

#include <utility>

OnKeyPress::OnKeyPress(int key, std::function<void()> function, ActivationMethod activationMethod)
{
    this->mKeys.push_back(key);
    this->mFunction = std::move(function);
    this->mActivationMethod = activationMethod;
}

OnKeyPress::OnKeyPress(std::list<int> keys, std::function<void()> function, ActivationMethod activationMethod) :
        OnKeyPress(*(keys.begin()), std::move(function), activationMethod)
{
    this->mKeys = std::move(keys);
}

std::list<int> OnKeyPress::getKeys() const
{
    return mKeys;
}

void OnKeyPress::setKey(std::list<int> keys)
{
    this->mKeys = std::move(keys);
}

std::function<void()> OnKeyPress::getFunction() const
{
    return mFunction;
}

void OnKeyPress::setFunction(const std::function<void()> &function)
{
    mFunction = function;
}

ActivationMethod OnKeyPress::getActivationMethod() const
{
    return mActivationMethod;
}

void OnKeyPress::setActivationMethod(ActivationMethod activationMethod)
{
    mActivationMethod = activationMethod;
}

void OnKeyPress::executeFunction()
{
    this->mHasActivatedFunction = true;
    this->mFunction();
}

bool OnKeyPress::hasActivatedFunction() const
{
    return this->mHasActivatedFunction;
}

void OnKeyPress::setHasActivatedFunction(bool hasActivatedFunction)
{
    this->mHasActivatedFunction = hasActivatedFunction;
}
