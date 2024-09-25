//
// Created by Elias on 25/09/2024.
//

#ifndef SAMPLEPROJECT_COMMAND_H
#define SAMPLEPROJECT_COMMAND_H


#include <Command/CommandEnums.h>

class Command
{
public:
    Command(PrimaryCMD cmd, ObjectType objecttype, int id, SecondaryCMD secondarycmd);

    PrimaryCMD primaryCmd_;
    SecondaryCMD secondaryCmd_;
    int id_;
    ObjectType objectType_;

};


#endif //SAMPLEPROJECT_COMMAND_H
