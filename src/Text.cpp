//
// Created by Elias Aggergaard Larsen on 21/11/2024.
//

#include <utility>

#include "include/EngineBase/Text.h"

Text::Text(std::string  text, int x, int y, int fontSize) : text_(std::move(text)), x_(x), y_(y), fontSize_(fontSize)
{
}

std::string Text::getText() const
{
    return text_;
}

void Text::setText(const std::string& text)
{
    text_ = text;
}

int Text::getX() const
{
    return x_;
}

void Text::setX(int x)
{
    x_ = x;
}

int Text::getY() const
{
    return y_;
}

void Text::setY(int y)
{
    y_ = y;
}

int Text::getFontSize() const
{
    return fontSize_;
}

void Text::setFontSize(int font_size)
{
    fontSize_ = font_size;
}
