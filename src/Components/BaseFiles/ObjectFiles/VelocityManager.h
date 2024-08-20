//
// Created by Elias on 20/08/2024.
//

#ifndef ROGUELIKEV2_VELOCITYMANAGER_H
#define ROGUELIKEV2_VELOCITYMANAGER_H

class DrawAbleObject;
class VelocityManager
{

public:
    VelocityManager(DrawAbleObject* drawAbleObject);
    void setVelocity(int xSpeed, int ySpeed);
    void updatePosition();
private:
    DrawAbleObject* mDrawAbleObject;
    int mXSpeed;
    int mYSpeed;
};


#endif //ROGUELIKEV2_VELOCITYMANAGER_H
