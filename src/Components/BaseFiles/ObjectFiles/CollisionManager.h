//
// Created by Elias Aggergaard Larsen on 17/08/2024.
//

#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

typedef enum
{
    Collide,
    HandleElseWhere
} CollisionMode;

class CollisionManager
{
public:
    CollisionManager();


    CollisionMode getCollisionMode();
    void setCollisionMode(CollisionMode collisionMode);

private:
    CollisionMode mCollisionMode;
};


#endif //COLLISIONMANAGER_H
