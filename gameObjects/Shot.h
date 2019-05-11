//
// Created by Nicolas Haenni on 2019-05-11.
//

#ifndef HARAMBE_SHOT_H
#define HARAMBE_SHOT_H


#include "GameObject.h"

class Shot: public GameObject
{
public:
    Shot(int x, int y);
    void move();
};


#endif //HARAMBE_SHOT_H
