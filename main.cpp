#include <iostream>

#include "DrawAbleObject.h"
#include "TextureController.h"

int main()
{
    std::shared_ptr<TextureController> textureController = std::make_shared<TextureController>();
    textureController->addTexture("../BBishop.png", 0, 0);
    auto object = new DrawAbleObject(50, 50, 50, 50, textureController);

    textureController->startGUI();

    return 0;
}
