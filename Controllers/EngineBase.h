//
// Created by Elias Aggergaard Larsen on 27/07/2024.
//

#ifndef ENGINEBASE_H
#define ENGINEBASE_H
#include <TextureController.h>


class EngineBase
{
public:
    static void addTexture(const std::string&, int firstIndex, int secondIndex);
    static void setScene(int scene);
    static void startGUI();

private:
    static TextureController mTextureController;
};


#endif //ENGINEBASE_H
