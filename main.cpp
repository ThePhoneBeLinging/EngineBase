#include <iostream>
#include <ObjectController.h>
#include "DrawAbleObject.h"
#include "EngineBase.h"
#include "RectangleButton.h"
#include "TextureController.h"

int main()
{
    std::shared_ptr<TextureController> textureController = std::make_shared<TextureController>();
    textureController->addTexture("../BBishop.png", 0, 0);
    textureController->addTexture("../BKnight.png", 1, 0);
    auto object = new RectangleButton(50, 50, 50, 50, textureController);
    auto otherObject = new RectangleButton(50, 50, 50, 50, textureController);
    auto boom = new RectangleButton(50, 50, 50, 50, textureController);
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
    auto thirdThind = [&textureController](Button* button)
    {
        std::cout << "BOOM Pressed" << std::endl;
    };
    object->setOnClick(toDoOnClick);
    otherObject->setOnClick(otherthing);
    boom->setOnClick(thirdThind);
    EngineBase::startGUI();

    return 0;
}
