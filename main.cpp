#include <iostream>
#include <ObjectController.h>
#include "DrawAbleObject.h"
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
    object->setLayer(1);
    boom->setTextureIndex(1);
    otherObject->setTextureIndex(1);
    otherObject->setScene(1);
    auto toDoOnClick = [&textureController](Button* button)
    {
        textureController->setScene(1);
    };
    auto otherthing = [&textureController](Button* button)
    {
        textureController->setScene(0);
    };
    object->setOnClick(toDoOnClick);
    otherObject->setOnClick(otherthing);
    textureController->startGUI();

    return 0;
}
