//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef TEXTURECONTROLLER_H
#define TEXTURECONTROLLER_H
#include <vector>
#include <thread>

#include "cmake-build-debug/_deps/raylib-src/src/raylib.h"


class TextureController
{
public:
    TextureController();
    void addTexture(const std::string& texturePath, int firstIndex, int secondIndex);
    Texture2D getTexture(int firstIndex, int secondIndex);

private:
    std::vector<std::vector<Texture2D>> mTextures;
    int spacesPerResize = 50;
    std::thread mThread;
};


#endif //TEXTURECONTROLLER_H
