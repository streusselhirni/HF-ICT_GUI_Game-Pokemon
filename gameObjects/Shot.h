//
// Created by Nicolas Haenni on 2019-05-11.
//

#ifndef HARAMBE_SHOT_H
#define HARAMBE_SHOT_H


#include "GameObject.h"

class Shot: public GameObject
{
private:
    int speed;
    int angle;
    double t;
public:
    Shot(int x, int y, int speed, int angle);
    void move();
};


#endif //HARAMBE_SHOT_H
