//
// Created by Elias on 25/09/2024.
//

#include "EngineBase/Command.h"

Command::Command(PrimaryCMD cmd, ObjectType objecttype, int id, SecondaryCMD secondarycmd) : primaryCmd_(cmd), objectType_(objecttype), id_(id), secondaryCmd_(secondarycmd)
{}
