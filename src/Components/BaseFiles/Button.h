//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef BUTTON_H
#define BUTTON_H
#include <functional>
class DrawAbleObject;

class Button
{
public:
    Button(DrawAbleObject* drawAbleObject);
	virtual ~Button() = default;
	virtual void onClick();
	void setOnClick(std::function<void(DrawAbleObject*)> function);

private:
	std::function<void(DrawAbleObject*)> mFunction;
	DrawAbleObject* mDrawAble;
};


#endif //BUTTON_H
