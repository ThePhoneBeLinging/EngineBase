//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef TEXTURECONTROLLER_H
#define TEXTURECONTROLLER_H
#include <list>
#include <vector>
#include <thread>
#include <Components/TextureToLoad.h>

#include "raylib.h"


class TextureController
{
public:
    static void addTexture(const std::string& texturePath, int firstIndex, int secondIndex);
    static void draw(int x, int y, int height, int width, int firstIndex, int secondIndex);
    static void initWindow();
    static void addTextureToLoad(const std::string& texturePath, int firstIndex, int secondIndex);
    static void initializeQueuedTextures();

    typedef enum
    {
        black = 1,
        white = 2
    } color;

private:
    static std::vector<std::vector<Texture2D>> mTextures;
    static int spacesPerResize;
    static bool mWindowInitialized;
    static std::list<TextureToLoad> mTexturesToLoad;
    static std::mutex mTextureQueueLock;
};


#endif //TEXTURECONTROLLER_H
