//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef BUTTON_H
#define BUTTON_H
#include <PointCheckerObject.h>


class Button : public PointCheckerObject
{
public:
	Button(int x, int y, int height, int width, std::shared_ptr<TextureController>& textureController);
	virtual void onClick() = 0;
	void deleteObject() override;
};


#endif //BUTTON_H
