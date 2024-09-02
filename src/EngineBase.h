//
// Created by Elias Aggergaard Larsen on 02/09/2024.
//

#ifndef ENGINEBASE_H
#define ENGINEBASE_H
#include <functional>
#include <string>


class EngineBase
{
public:
    static int loadTexture(const std::string& path);
    static void startGUI(const std::function<void(float deltaTime)>& update);

private:
    static inline bool windowInitialized_ = false;
    static void initializeWindow();
};


#endif //ENGINEBASE_H
