//
// Created by Elias Aggergaard Larsen on 25/07/2024.
//

#ifndef BUTTON_H
#define BUTTON_H
#include <functional>


class Button
{
public:
	virtual ~Button() = default;
	Button() = default;
	virtual void onClick();
	void setOnClick(std::function<void(Button*)> function);

private:
	std::function<void(Button*)> mFunction;
};


#endif //BUTTON_H
