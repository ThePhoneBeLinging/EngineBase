#include <iostream>
#include <ObjectController.h>
#include "DrawAbleObject.h"
#include "DropDownMenu.h"
#include "EngineBase.h"
#include "RectangleButton.h"
#include "TextureController.h"

int main()
{
    TextureController::addTexture("../src/BBishop.png", 0, 0);
    TextureController::addTexture("../src/BKnight.png", 1, 0);
    auto object = new RectangleButton(50, 50, 50, 50);
    auto otherObject = new RectangleButton(50, 50, 50, 50);
    auto boom = new RectangleButton(50, 50, 50, 50);
    boom->setTextureIndex(1);
    otherObject->setTextureIndex(1);
    otherObject->addToScene(1);
    object->addToScene(0);
    boom->addToScene(0);
    object->setZ(1);
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
    object->setOnClick(toDoOnClick);
    otherObject->setOnClick(otherthing);
    boom->setOnClick(thirdThind);
    EngineBase::startGUI();

    return 0;
}
