#include <iostream>

#include "DrawAbleObject.h"
#include "RectangleButton.h"
#include "TextureController.h"

int main()
{
    std::shared_ptr<TextureController> textureController = std::make_shared<TextureController>();
    textureController->addTexture("../BBishop.png", 0, 0);
    auto object = new RectangleButton(50, 50, 50, 50, textureController);
    auto toDoOnClick = []()
    {
        std::cout << "Lambda function called!" << std::endl;
    };
    object->setOnClick(toDoOnClick);
    textureController->startGUI();

    return 0;
}
