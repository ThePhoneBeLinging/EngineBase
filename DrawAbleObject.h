//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H



class DrawAbleObject
{
public:
    DrawAbleObject(int textureIndex, int height, int width);
    void draw();

private:
    int mTextureIndex;
    int mTextureState;
    int mHeight;
    int mWidth;
    bool mIsVisible;
};



#endif //DRAWABLEOBJECT_H
