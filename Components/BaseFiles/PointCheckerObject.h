//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef POINTCHECKEROBJECT_H
#define POINTCHECKEROBJECT_H
#include <DrawAbleObject.h>


class PointCheckerObject : public DrawAbleObject
{
public:
    PointCheckerObject(int x, int y, int height, int width, std::shared_ptr<TextureController>& textureController);

protected:
    virtual bool isPointInside(int xToCheck, int yToCheck) = 0;
};


#endif //POINTCHECKEROBJECT_H
