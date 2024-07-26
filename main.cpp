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
    otherObject->setTextureIndex(1);
    auto toDoOnClick = [](Button* button)
    {
        ObjectController::setScene(1);
    };
    object->setOnClick(toDoOnClick);
    textureController->startGUI();

    return 0;
}
