//
// Created by Elias Aggergaard Larsen on 30/07/2024.
//

#ifndef ONKEYPRESS_H
#define ONKEYPRESS_H
#include <functional>
#include <list>
#include <string>

typedef enum
{
    TriggerOnce,
    TriggerContinuously

} ActivationMethod;

class OnKeyPress
{
public:
    OnKeyPress(int key, std::function<void()> function, ActivationMethod activationMethod);
    OnKeyPress(std::list<int> keys, std::function<void()> function, ActivationMethod activationMethod);
    std::list<int> getKeys() const;
    void setKey(std::list<int> keys);
    std::function<void()> getFunction() const;
    void setFunction(const std::function<void()>& function);
    ActivationMethod getActivationMethod() const;
    void setActivationMethod(ActivationMethod activationMethod);
    bool hasActivatedFunction() const;
    void setHasActivatedFunction(bool hasActivatedFunction);
    void executeFunction();

private:
    std::list<int> mKeys;
    std::function<void()> mFunction;
    ActivationMethod mActivationMethod;
    bool mHasActivatedFunction = false;
};


#endif //ONKEYPRESS_H
