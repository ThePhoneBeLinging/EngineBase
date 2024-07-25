//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#include <ObjectController.h>

#include "button.h"

Button::Button()
{
    ObjectController::addButton(this);
}
