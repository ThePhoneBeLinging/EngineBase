//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef RECTANGLEOBJECT_H
#define RECTANGLEOBJECT_H
#include <PointCheckerObject.h>


class RectangleObject : public PointCheckerObject
{
public:
    RectangleObject(int x, int y, int height, int width, std::shared_ptr<TextureController>& textureController);
    bool isPointInside(int xToCheck, int yToCheck) override;
};


#endif //RECTANGLEOBJECT_H
