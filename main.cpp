#include <iostream>
#include "DrawAbleObject.h"
#include "EngineBase.h"
#include "TextureController.h"

int main()
{
    TextureController::addTexture("../src/BBishop.png", 0, 0);
    TextureController::addTexture("../src/BKnight.png", 1, 0);
    auto object = new DrawAbleObject(50, 50, 50, 50);
    object->mTextureManager.setZ(-1);
    object->addToScene(0);

    auto otherObject = new DrawAbleObject(150, 50, 50, 50);
    otherObject->mTextureManager.setTextureIndex(1);
    otherObject->mTextureManager.setTextureSecondIndex(0);
    otherObject->addToScene(1);

    auto boom = new DrawAbleObject(50, 50, 50, 50);
    boom->mTextureManager.setTextureIndex(1);
    boom->addToScene(0);
    boom->mDragAble.setDragable(true);
    object->mDragAble.setDragable(false);
    auto dean = new DrawAbleObject(0, 50, 50, 50);
    boom->mConnectionManager.connectDrawAble(dean);
    auto toDoOnClick = [](Button* button)
    {
        EngineBase::setScene(1);
    };
    auto otherthing = [](Button* button)
    {
        EngineBase::setScene(0);
    };
    auto thirdThind = [](Button* button)
    {
        std::cout << "BOOM Pressed" << std::endl;
    };
    object->mButton.setOnClick(toDoOnClick);
    otherObject->mButton.setOnClick(otherthing);
    EngineBase::startGUI();

    return 0;
}
