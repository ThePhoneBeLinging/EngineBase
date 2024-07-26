//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef BUTTON_H
#define BUTTON_H
#include <functional>
#include <PointCheckerObject.h>


class Button : public PointCheckerObject
{
public:
	Button(int x, int y, int height, int width, std::shared_ptr<TextureController>& textureController);
	virtual void onClick();
	void deleteObject() override;
	void setOnClick(std::function<void(Button*)> function);

private:
	std::function<void(Button*)> mFunction;
};


#endif //BUTTON_H
