//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef TEXTURECONTROLLER_H
#define TEXTURECONTROLLER_H
#include <vector>
#include <thread>

#include "raylib.h"


class TextureController
{
public:
    static void addTexture(const std::string& texturePath, int firstIndex, int secondIndex);
    static void draw(int x, int y, int height, int width, int firstIndex, int secondIndex);
    static bool isWindowInitialized();
    static void initWindow();

private:
    static std::vector<std::vector<Texture2D>> mTextures;
    static int spacesPerResize;
    static bool mWindowInitialized;
};


#endif //TEXTURECONTROLLER_H
