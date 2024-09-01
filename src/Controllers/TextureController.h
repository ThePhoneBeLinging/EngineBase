//
// Created by Elias Aggergaard Larsen on 01/09/2024.
//

#ifndef TEXTURECONTROLLER_H
#define TEXTURECONTROLLER_H
#include <vector>

#include "raylib.h"
#include "Objects/DrawAble.h"


class TextureController
{
public:
    static int loadTexture(const std::string& path);
    static void drawTexture(DrawAble* object);
    static void initializeWindow();

private:
    static inline std::vector<std::shared_ptr<Texture2D>> textures_ = {};
};


#endif //TEXTURECONTROLLER_H
