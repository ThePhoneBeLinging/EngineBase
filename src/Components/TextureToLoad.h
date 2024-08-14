//
// Created by Elias Aggergaard Larsen on 14/08/2024.
//

#ifndef TEXTURETOLOAD_H
#define TEXTURETOLOAD_H
#include <string>


class TextureToLoad
{
public:
    TextureToLoad(std::string texturePath, int primaryIndex, int secondaryIndex);
    std::string mTexturePath;
    int mPrimaryIndex;
    int mSecondaryIndex;
};


#endif //TEXTURETOLOAD_H
