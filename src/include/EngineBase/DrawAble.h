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

    void setPosition(double x, double y);

    void updatePosition(double deltaX, double deltaY);

    void setSize(int width, int height);

    void setHeightPreserveAspectRatio(int height);

    void setWidthPreserveAspectRatio(int width);

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

    [[nodiscard]] const std::string* getTextureLocation() const;

    void setTextureLocation(const std::string* texture_index);

    [[nodiscard]] int getID() const;

    void setID(int id);

    void setDrawAble(const std::shared_ptr<DrawAble>& drawAble);

    [[nodiscard]] std::weak_ptr<DrawAble> getDrawAblePtr() const;

    void setPositionIsAffectedByOffset(bool positionIsAffectedByOffset);

    [[nodiscard]] bool getPositionIsAffectedByOffset() const;

private:
    std::shared_ptr<DrawAble> drawAble_;
    double x_;
    double y_;
    int z_;
    int width_;
    int height_;
    const std::string* textureLocation_;
    int id_;
    bool positionIsAffectedByOffset_;
};


#endif //DRAWABLE_H
