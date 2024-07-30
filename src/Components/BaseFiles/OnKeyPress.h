//
// Created by Elias Aggergaard Larsen on 30/07/2024.
//

#ifndef ONKEYPRESS_H
#define ONKEYPRESS_H
#include <functional>
#include <list>


class OnKeyPress
{
public:
    OnKeyPress(int key, std::function<void()> function, std::string activationMethod);
    OnKeyPress(std::list<int> keys, std::function<void()> function, std::string activationMethod);
    std::list<int> getKeys() const;
    void setKey(std::list<int> keys);
    std::function<void()> getFunction() const;
    void setFunction(const std::function<void()>& function);
    std::string getActivationMethod() const;
    void setActivationMethod(const std::string& activationMethod);

private:
    std::list<int> mKeys;
    std::function<void()> mFunction;
    std::string mActivationMethod;
};


#endif //ONKEYPRESS_H
