//
// Created by Elias Aggergaard Larsen on 27/07/2024.
//

#ifndef VISIBILITY_H
#define VISIBILITY_H


class Visibility
{
public:
    Visibility() = default;
    void setVisisble(bool visible);
    bool isVisisble();

private:
    bool mIsVisisble = true;
};


#endif //VISIBILITY_H
