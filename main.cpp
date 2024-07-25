#include <iostream>

#include "TextureController.h"

int main()
{
    std::shared_ptr<TextureController> textureController = std::make_shared<TextureController>();
    textureController->addTexture(LoadTexture("../BBishop.png"),1000,0);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
