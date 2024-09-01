//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//


#include "TextureController.h"

#include <EngineBase/EngineBase.h>

#include "ObjectController.h"

std::vector<std::vector<Texture2D>> TextureController::mTextures;
int TextureController::spacesPerResize = 50;
bool TextureController::mWindowInitialized = false;
std::list<TextureToLoad> TextureController::mTexturesToLoad;
std::mutex TextureController::mTextureQueueLock;
std::mutex TextureController::mHexColorsQueueLock;
std::list<HexColorToLoad> TextureController::mHexColorsToLoad;
int TextureController::mFollowAbleX;
int TextureController::mFollowAbleY;

//Used for loading a texture now
void TextureController::loadTexture(const std::string& texturePath, int firstIndex, int secondIndex)
{
    addTexture(LoadTexture(texturePath.c_str()), firstIndex, secondIndex);
}

void TextureController::addTexture(Texture2D texture, int primaryIndex, int secondaryIndex)
{
    while (mTextures.capacity() <= (unsigned)primaryIndex)
    {
        mTextures.resize(mTextures.capacity() + spacesPerResize);
    }
    while (mTextures[primaryIndex].capacity() <= (unsigned)secondaryIndex)
    {
        mTextures[primaryIndex].resize(mTextures[primaryIndex].capacity() + spacesPerResize);
    }
    mTextures[primaryIndex][secondaryIndex] = texture;
}

void TextureController::draw(DrawAbleObject* drawAble)
{
    int x = drawAble->getX();
    int y = drawAble->getY();
    int firstIndex = drawAble->mTextureManager.getTextureIndex();
    int secondIndex = drawAble->mTextureManager.getSecondTextureIndex();
    int height = drawAble->getHeight();
    int width = drawAble->getWidth();

    if (EngineBase::getObjectToFollow() != nullptr)
    {
        x -= EngineBase::getObjectToFollow()->getX() - mFollowAbleX;
        y -= EngineBase::getObjectToFollow()->getY() - mFollowAbleY;
    }

    if (mTextures.size() <= (unsigned) firstIndex)
    {
        return;
    }
    if (mTextures[firstIndex].size() <= (unsigned)secondIndex)
    {
        return;
    }
    Texture2D texture = mTextures[firstIndex][secondIndex];
    texture.height = height;
    texture.width = width;
    float scaleFactor = (GetScreenWidth() / 1280);
    Vector2 pos = {(float)x, (float)y};
    DrawTextureEx(texture, pos, 0, scaleFactor,WHITE);
}

void TextureController::initWindow()
{
    if (!mWindowInitialized)
    {
        int height = 720;
        int width = 1280;
        std::string title = "M3";
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        InitWindow(width, height, title.c_str());
        mWindowInitialized = true;
        loadTexture("Textures/MissingTexture.png", 0, 0);
    }
}

void TextureController::addTextureToLoad(const std::string& texturePath, int firstIndex, int secondIndex)
{
    std::lock_guard<std::mutex> lock(mTextureQueueLock);
    mTexturesToLoad.emplace_back(texturePath, firstIndex, secondIndex);
}

void TextureController::genColorFromHex(unsigned int hexValue, int primaryIndex, int secondaryIndex)
{
    std::lock_guard<std::mutex> lock(mHexColorsQueueLock);
    mHexColorsToLoad.emplace_back(hexValue, primaryIndex, secondaryIndex);
}

void TextureController::initializeQueuedTextures()
{
    std::lock_guard<std::mutex> lock(mTextureQueueLock);
    std::lock_guard<std::mutex> otherLock(mHexColorsQueueLock);
    for (const auto& textureToLoad : mTexturesToLoad)
    {
        loadTexture(textureToLoad.mTexturePath, textureToLoad.mPrimaryIndex, textureToLoad.mSecondaryIndex);
    }
    for (auto hexToLoad : mHexColorsToLoad)
    {
        addTexture(LoadTextureFromImage(GenImageColor(1, 1, GetColor(hexToLoad.hex))), hexToLoad.primaryIndex,
                   hexToLoad.secondaryIndex);
    }
    mTexturesToLoad.clear();
    mHexColorsToLoad.clear();
}

void TextureController::setObjectToFollow(DrawAbleObject* drawAbleToFollow)
{
    //TODO Unsafe while loop :)

    while (GetScreenHeight() == 0)
    {
    }

    int targetX = (GetScreenWidth() / 2) - (drawAbleToFollow->getWidth() / 2);
    int targetY = (GetScreenHeight() / 2) - (drawAbleToFollow->getHeight() / 2);
    mFollowAbleX = targetX;
    mFollowAbleY = targetY;
    int xOffset = targetX - drawAbleToFollow->getX();
    int yOffset = targetY - drawAbleToFollow->getY();


    ObjectController::offsetAllDrawAbles(xOffset, yOffset);
}

void TextureController::loadTexturePart(const std::string& texturePath, int firstIndex, int secondIndex,
                                        int width, int height)
{
    // Load the full texture
    auto fullImage = LoadImage(texturePath.c_str());

    // Create a sub-image from the full texture
    int x = 0;
    int y = 0;
    while (y > fullImage.height)
    {
        while (x > fullImage.width)
        {
            Image subImage = ImageFromImage(fullImage, {(float)x, (float)y, (float)width, (float)height});
            Texture2D subTexture = LoadTextureFromImage(subImage);
            addTexture(subTexture, firstIndex, secondIndex);
            x += width;
            secondIndex++;
        }
    }

    // Unload the full texture to free memory
    UnloadImage(fullImage);
}
