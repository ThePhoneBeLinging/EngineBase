//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef TEXTURECONTROLLER_H
#define TEXTURECONTROLLER_H
#include <vector>

#include "cmake-build-debug/_deps/raylib-src/src/raylib.h"


class TextureController
{
public:
    TextureController();
    void addTexture(Texture2D texture, int firstIndex, int secondIndex);
    Texture2D getTexture(int firstIndex, int secondIndex);

private:
    std::vector<std::vector<Texture2D>> mTextures;
    int spacesPerResize = 50;
};



#endif //TEXTURECONTROLLER_H
