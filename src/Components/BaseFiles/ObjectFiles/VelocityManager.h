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
private:
    DrawAbleObject* mDrawAbleObject;
};


#endif //ROGUELIKEV2_VELOCITYMANAGER_H
