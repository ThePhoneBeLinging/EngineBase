//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef TESTBUTTON_H
#define TESTBUTTON_H
#include <RectangleButton.h>


class TestButton : public RectangleButton
{
public:
    TestButton(int x, int y, int height, int width, std::shared_ptr<TextureController>& textureController);
    void onClick() override;
};


#endif //TESTBUTTON_H
