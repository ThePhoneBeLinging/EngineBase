//
// Created by eal on 10/24/24.
//

#ifndef ENGINEBASE_H
#define ENGINEBASE_H
#include <utility>
#include "GraphicsInterface/IGraphicsLibrary.h"


class EngineBase
{
public:
    static void init();
    static std::pair<int,int> getMousePos();
    static int loadTexture(const std::string& texturePath);
private:
    static inline IGraphicsLibrary* graphicsInterface_;
};



#endif //ENGINEBASE_H
