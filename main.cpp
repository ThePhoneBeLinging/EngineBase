#include <iostream>

#include "DrawAbleObject.h"
#include "ObjectController.h"
#include "TextureController.h"
#include <thread>

int main()
{
    std::shared_ptr<TextureController> textureController = std::make_shared<TextureController>();
    textureController->addTexture("../BBishop.png", 0, 0);
    //auto object = new DrawAbleObject(50, 50, 50, 50, textureController);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
