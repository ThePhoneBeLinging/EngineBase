//
// Created by Elias Aggergaard Larsen on 21/11/2024.
//

#ifndef TEXT_H
#define TEXT_H
#include <string>


class Text
{
public:
    Text(std::string  text, int x, int y, int fontSize);
    [[nodiscard]] std::string getText() const;
    void setText(const std::string& text);
    [[nodiscard]] int getX() const;
    void setX(int x);
    [[nodiscard]] int getY() const;
    void setY(int y);
    [[nodiscard]] int getFontSize() const;
    void setFontSize(int font_size);

private:
    std::string text_;
    int x_;
    int y_;
    int fontSize_;
};



#endif //TEXT_H
