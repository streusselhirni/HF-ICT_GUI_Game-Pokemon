#ifndef HARAMBE_SHOT_H
#define HARAMBE_SHOT_H


#include "GameObject.h"
#include "QMovie"

class Shot : public GameObject {
private:
    friend class Player;

    double const g = 9.81;
    int speed;
    int angle;
    double t;
    bool fired;

    Shot(int x, int y, int speed, int angle);

public:

    void move(uint64_t delta) override;

    short getBodyType() const override;

    void setSpeed(int speed);

    void setAngle(int angle);

    void fire();

    void paint(QPainter *painter) override;

    void onOutOfBound() override;
};


#endif //HARAMBE_SHOT_H
