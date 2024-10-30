//
// Created by eal on 10/30/24.
//

#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <functional>
#include <vector>


class DrawAble
{
public:
    DrawAble();
    virtual ~DrawAble() = default;
    [[nodiscard]] int getX() const;
    void setX(int x);
    [[nodiscard]] int getY() const;
    void setY(int y);
    [[nodiscard]] int getWidth() const;
    void setWidth(int width);
    [[nodiscard]] int getHeight() const;
    void setHeight(int height);
    [[nodiscard]] int getTextureIndex() const;
    void setTextureIndex(int texture_index);
    [[nodiscard]] int* getID() const;
    void setID(int* id);
    void subscribe(const std::function<void()>& callback);

private:
    int x_;
    int y_;
    int width_;
    int height_;
    int textureIndex_;
    int* id_;
    std::vector<std::function<void()>> statusSubscribedFunctions_;
};


#endif //DRAWABLE_H
