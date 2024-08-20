//
// Created by Elias Aggergaard Larsen on 28/07/2024.
//

#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H
#include <list>


class DrawAbleObject;

class ConnectionManager
{
public:
    ConnectionManager(DrawAbleObject* drawAbleObject);
    void connectDrawAble(DrawAbleObject* drawAble);
    void disconnectDrawAble(DrawAbleObject* drawAble);
    std::list<DrawAbleObject*> getConnectedObjects();

private:
    void sortList();
    std::list<DrawAbleObject*> mConnectedObjects;
};


#endif //CONNECTIONMANAGER_H
