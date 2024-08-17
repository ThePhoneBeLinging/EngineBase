//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef TEXTURECONTROLLER_H
#define TEXTURECONTROLLER_H
#include <list>
#include <vector>
#include <thread>
#include <Components/TextureToLoad.h>
#include <EngineBase/DrawAbleObject.h>

#include "raylib.h"
#include "Components/HexColorToLoad.h"


class TextureController
{
public:
    static void loadTexture(const std::string& texturePath, int firstIndex, int secondIndex);
    static void draw(DrawAbleObject* drawAble);
    static void initWindow();
    static void addTextureToLoad(const std::string& texturePath, int firstIndex, int secondIndex);
    static void genColorFromHex(unsigned int hexValue, int primaryIndex, int secondaryIndex);
    static void initializeQueuedTextures();
    static void setObjectToFollow(DrawAbleObject* drawAbleToFollow);

private:
    static std::vector<std::vector<Texture2D>> mTextures;
    static int spacesPerResize;
    static bool mWindowInitialized;
    static std::list<TextureToLoad> mTexturesToLoad;
    static std::mutex mTextureQueueLock;
    static std::list<HexColorToLoad> mHexColorsToLoad;
    static std::mutex mHexColorsQueueLock;
    static void addTexture(Texture2D texture, int primaryIndex, int secondaryIndex);
    static int mFollowAbleX;
    static int mFollowAbleY;
};


#endif //TEXTURECONTROLLER_H
