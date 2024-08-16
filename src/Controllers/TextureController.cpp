//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//


#include "TextureController.h"
#include "ObjectController.h"

std::vector<std::vector<Texture2D>> TextureController::mTextures;
int TextureController::spacesPerResize = 50;
bool TextureController::mWindowInitialized = false;
std::list<TextureToLoad> TextureController::mTexturesToLoad;
std::mutex TextureController::mTextureQueueLock;
std::mutex TextureController::mHexColorsQueueLock;
std::list<HexColorToLoad> TextureController::mHexColorsToLoad;

//Used for loading a texture now
void TextureController::loadTexture(const std::string& texturePath, int firstIndex, int secondIndex)
{
    addTexture(LoadTexture(texturePath.c_str()), firstIndex, secondIndex);
}

void TextureController::addTexture(Texture2D texture, int primaryIndex, int secondaryIndex)
{
    while (mTextures.capacity() <= primaryIndex)
    {
        mTextures.resize(mTextures.capacity() + spacesPerResize);
    }
    while (mTextures[primaryIndex].capacity() <= secondaryIndex)
    {
        mTextures[primaryIndex].resize(mTextures[primaryIndex].capacity() + spacesPerResize);
    }
    mTextures[primaryIndex][secondaryIndex] = texture;
}

void TextureController::draw(DrawAbleObject* drawAble)
{
    int firstIndex = drawAble->mTextureManager.getTextureIndex();
    int secondIndex = drawAble->mTextureManager.getSecondTextureIndex();
    int height = drawAble->getHeight();
    int width = drawAble->getWidth();
    if (mTextures.size() <= firstIndex)
    {
        return;
    }
    if (mTextures[firstIndex].size() <= secondIndex)
    {
        return;
    }
    Texture2D texture = mTextures[firstIndex][secondIndex];
    texture.height = height;
    texture.width = width;
    float scaleFactor = (GetScreenWidth() / 1280);
    Vector2 pos = {(float)drawAble->getX(), (float)drawAble->getY()};
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
