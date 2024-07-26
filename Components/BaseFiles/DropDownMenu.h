//
// Created by Elias Aggergaard Larsen on 26/07/2024.
//

#ifndef DROPDOWNMENU_H
#define DROPDOWNMENU_H
#include <DrawAbleObject.h>
#include <list>


class DropDownMenu : public DrawAbleObject
{
public:
    DropDownMenu(int x, int y, int height, int width, std::shared_ptr<TextureController>& textureController);

private:
};


#endif //DROPDOWNMENU_H
