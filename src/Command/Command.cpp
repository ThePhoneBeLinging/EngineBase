//
// Created by Elias on 25/09/2024.
//

#include <stdexcept>
#include "EngineBase/Command.h"

Command::Command(PrimaryCMD cmd, ObjectType objecttype, int id, SecondaryCMD secondarycmd, float value) : primaryCmd_(
        cmd), objectType_(objecttype), id_(id), secondaryCmd_(secondarycmd), value_(value)
{}

Command::Command(PrimaryCMD cmd)
{
    if (cmd != PrimaryCMD::DONEWRITING && cmd != PrimaryCMD::SORTDRAWABLES)
    {
        throw std::invalid_argument(
                "This constructor is only for PrimaryCMD::DONEWRITING and PrimaryCMD::SORTDRAWABLES");
    }
    primaryCmd_ = cmd;
    objectType_ = ObjectType::DRAWABLE;
    secondaryCmd_ = SecondaryCMD::X;
    id_ = 0;
    value_ = 0;
}
