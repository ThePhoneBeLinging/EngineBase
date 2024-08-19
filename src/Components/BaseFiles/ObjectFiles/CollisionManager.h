//
// Created by Elias Aggergaard Larsen on 17/08/2024.
//

#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include <list>
class DrawAbleObject;

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
    void setCollidingObjects(std::list<DrawAbleObject*> collidingObjects);
    void addCollidingObject(DrawAbleObject* drawAble);
    std::list<DrawAbleObject*>& getCollidingObjects();

private:
    CollisionMode mCollisionMode;
    std::list<DrawAbleObject*> mCollidingObjects;
};


#endif //COLLISIONMANAGER_H
