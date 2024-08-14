//
// Created by Elias Aggergaard Larsen on 14/08/2024.
//

#include "TextureToLoad.h"

#include <string>
#include <utility>

TextureToLoad::TextureToLoad(std::string texturePath, int primaryIndex, int secondaryIndex) :
    mTexturePath(std::move(texturePath)),
    mPrimaryIndex(primaryIndex), mSecondaryIndex(secondaryIndex)
{
}
