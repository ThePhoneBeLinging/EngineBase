//
// Created by Elias on 25/09/2024.
//

#ifndef SAMPLEPROJECT_COMMAND_H
#define SAMPLEPROJECT_COMMAND_H


#include <Command/CommandEnums.h>

class Command
{
public:
    Command(PrimaryCMD cmd, ObjectType objecttype, int id, SecondaryCMD secondarycmd, float value);

    explicit Command(PrimaryCMD cmd);

    PrimaryCMD primaryCmd_;
    ObjectType objectType_;
    int id_;
    SecondaryCMD secondaryCmd_;
    float value_;

};


#endif //SAMPLEPROJECT_COMMAND_H
