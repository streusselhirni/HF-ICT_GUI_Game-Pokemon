#ifndef HARAMBE_SHOT_H
#define HARAMBE_SHOT_H


#include "GameObject.h"

class Shot : public GameObject {
private:
    double const g = 9.81;
    int speed;
    int angle;
    double t;
public:
    Shot(int x, int y, int speed, int angle);

    void move(uint64_t delta) override;

    short getBodyType() const override;
};


#endif //HARAMBE_SHOT_H
