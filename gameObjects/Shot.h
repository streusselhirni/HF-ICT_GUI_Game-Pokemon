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
    int rotation;

    Shot(int x, int y, int speed, int angle);

public:
    bool getFired();

    void init(int x, int y, int speed, int angle, double t);

    void move(uint64_t delta) override;

    short getBodyType() const override;

    void paint(QPainter *painter) override;

    void onOutOfBound() override;
};


#endif //HARAMBE_SHOT_H
