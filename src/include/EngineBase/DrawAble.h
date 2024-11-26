//
// Created by eal on 10/30/24.
//

#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <memory>
#include <mutex>


class DrawAble
{
public:
    DrawAble();
    explicit DrawAble(const DrawAble* drawAble);
    virtual ~DrawAble() = default;
    [[nodiscard]] double getX() const;
    void setX(double x);
    [[nodiscard]] double getY() const;
    void setY(double y);
    [[nodiscard]] int getZ() const;
    void setZ(int z);
    [[nodiscard]] int getWidth() const;
    void setWidth(int width);
    [[nodiscard]] int getHeight() const;
    void setHeight(int height);
    [[nodiscard]] int getTextureIndex() const;
    void setTextureIndex(int texture_index);
    [[nodiscard]] int getID() const;
    void setID(int id);
    void setDrawAble(const std::shared_ptr<DrawAble>& drawAble);
    [[nodiscard]] std::weak_ptr<DrawAble> getDrawAblePtr() const;

private:
    std::shared_ptr<DrawAble> drawAble_;
    double x_;
    double y_;
    int z_;
    int width_;
    int height_;
    int textureIndex_;
    int id_;
    //TODO Upgrade dataStructure to not have mutex be necessary
    std::unique_ptr<std::mutex> mutex_;
};


#endif //DRAWABLE_H
