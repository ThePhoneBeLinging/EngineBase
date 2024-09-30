//
// Created by Elias on 25/09/2024.
//

#ifndef SAMPLEPROJECT_COMMANDENUMS_H
#define SAMPLEPROJECT_COMMANDENUMS_H

enum class PrimaryCMD
{
    UPDATE,
    DELETE,
    DONEWRITING,
    SORTDRAWABLES,
};

enum class SecondaryCMD
{
    X,
    Y,
    Z,
    WIDTH,
    HEIGHT,
    TEXTUREINDEX,
    XSPEED,
    YSPEED,
    XTARGET,
    YTARGET
};

enum class ObjectType
{
    DRAWABLE,
    SPEEDABLE,
    COLLIDABLE,
    DRAGABLE
};

#endif //SAMPLEPROJECT_COMMANDENUMS_H
