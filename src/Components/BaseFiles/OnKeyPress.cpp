//
// Created by Elias Aggergaard Larsen on 30/07/2024.
//

#include "OnKeyPress.h"

#include <utility>

OnKeyPress::OnKeyPress(int key, std::function<void()> function, std::string activationMethod)
{
    this->mKeys.push_back(key);
    this->mFunction = std::move(function);
    this->mActivationMethod = std::move(activationMethod);
}

OnKeyPress::OnKeyPress(std::list<int> keys, std::function<void()> function, std::string activationMethod)
{
    this->mKeys = std::move(keys);
    this->mFunction = std::move(function);
    this->mActivationMethod = std::move(activationMethod);
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

void OnKeyPress::setFunction(const std::function<void()>& function)
{
    mFunction = function;
}

std::string OnKeyPress::getActivationMethod() const
{
    return mActivationMethod;
}

void OnKeyPress::setActivationMethod(const std::string& activationMethod)
{
    mActivationMethod = activationMethod;
}
