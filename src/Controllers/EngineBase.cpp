//
// Created by Elias Aggergaard Larsen on 27/07/2024.
//

#include "EngineBase/EngineBase.h"

#include "TextureController.h"
#include "ObjectController.h"
#include "Utility/Timer.h"
#include "EngineBase/HotKeyManager.h"

bool EngineBase::mShouldAppClose = false;
bool EngineBase::mShowFPS = false;
std::mutex EngineBase::mAppCloseLock;
std::mutex EngineBase::mFPSLock;
std::mutex EngineBase::mObjectToFollowLock;

DrawAbleObject* EngineBase::mObjectToFollow = nullptr;


void EngineBase::addTexture(const std::string& texturePath, int firstIndex, int secondIndex)
{
    TextureController::addTextureToLoad(texturePath, firstIndex, secondIndex);
}

void EngineBase::addHexColor(unsigned int hexValue, int primaryIndex, int secondaryIndex)
{
    TextureController::genColorFromHex(hexValue, primaryIndex, secondaryIndex);
}

void EngineBase::setScene(int scene)
{
    ObjectController::mSceneManager.setScene(scene);
}

int EngineBase::getScene()
{
    return ObjectController::mSceneManager.getScene();
}

void EngineBase::startGUI()
{
    TextureController::initWindow();
    ObjectController::keepDrawingObjects();
    std::lock_guard<std::mutex> lock(mAppCloseLock);
    mShouldAppClose = true;
}

bool EngineBase::shouldAppClose()
{
    std::lock_guard<std::mutex> lock(mAppCloseLock);
    return mShouldAppClose;
}

void EngineBase::toggleFPSCounter()
{
    std::lock_guard<std::mutex> lock(mFPSLock);
    mShowFPS = !mShowFPS;
}

bool EngineBase::getShowFPS()
{
    std::lock_guard<std::mutex> lock(mFPSLock);
    return mShowFPS;
}

void EngineBase::setObjectToFollow(DrawAbleObject* drawAble)
{
    std::lock_guard<std::mutex> lock(mObjectToFollowLock);

    mObjectToFollow = drawAble;
    TextureController::setObjectToFollow(mObjectToFollow);
}

DrawAbleObject* EngineBase::getObjectToFollow()
{
    std::lock_guard<std::mutex> lock(mObjectToFollowLock);
    return mObjectToFollow;
}

void EngineBase::updatePositionOfObjects()
{
    ObjectController::updateVelocityOfAllObjects();
}


void EngineBase::attachUpdateFunction(const std::function<void()>& updateFunction, int updatesPerSecond)
{
    int timeInMilliseconds = 1000 / updatesPerSecond;
    auto loopManager = Timer(timeInMilliseconds);
    loopManager.start();
    while (!shouldAppClose())
    {
        int timeBeforeNextUpdate = loopManager.milliSecondsLeft();

        if (timeBeforeNextUpdate > 3)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(timeBeforeNextUpdate - 3));
        }
        if (timeBeforeNextUpdate != 0)
        {
            continue;
        }
        loopManager.start();
        EngineBase::updatePositionOfObjects();
        HotKeyManager::handleHotKeys();
        updateFunction();
    }
}

