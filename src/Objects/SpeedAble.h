//
// Created by eal on 10/23/24.
//

#ifndef SPEEDABLE_H
#define SPEEDABLE_H



class SpeedAble
{
public:
    explicit SpeedAble(int id, int xSpeed, int ySpeed);
    ~SpeedAble() = default;
    void update(float deltaTime) const;
    [[nodiscard]] int id() const;
private:
    int id_;
    int xSpeed_;
    int ySpeed_;

};



#endif //SPEEDABLE_H
