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
#include "Components/HexColorToLoad.h"


class TextureController
{
public:
    static void loadTexture(const std::string& texturePath, int firstIndex, int secondIndex);
    static void draw(int x, int y, int height, int width, int firstIndex, int secondIndex);
    static void initWindow();
    static void addTextureToLoad(const std::string& texturePath, int firstIndex, int secondIndex);
    static void genColorFromHex(unsigned int hexValue, int primaryIndex, int secondaryIndex);
    static void initializeQueuedTextures();


private:
    static std::vector<std::vector<Texture2D>> mTextures;
    static int spacesPerResize;
    static bool mWindowInitialized;
    static std::list<TextureToLoad> mTexturesToLoad;
    static std::mutex mTextureQueueLock;
    static std::list<HexColorToLoad> mHexColorsToLoad;
    static std::mutex mHexColorsQueueLock;
    static void addTexture(Texture2D texture, int primaryIndex, int secondaryIndex);
};


#endif //TEXTURECONTROLLER_H
