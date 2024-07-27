//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef BUTTON_H
#define BUTTON_H
#include <DrawAbleObject.h>
#include <functional>


class Button : public DrawAbleObject
{
public:
	Button(int x, int y, int height, int width);
	virtual void onClick();
	void deleteObject() override;
	void setOnClick(std::function<void(Button*)> function);
	void addToScene(int scene) override;

private:
	std::function<void(Button*)> mFunction;
};


#endif //BUTTON_H
