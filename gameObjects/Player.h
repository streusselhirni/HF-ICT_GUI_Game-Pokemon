//
// Created by Nicolas Haenni on 2019-05-11.
//

#ifndef HARAMBE_PLAYER_H
#define HARAMBE_PLAYER_H

#include "GameObject.h"

class Player: public GameObject
{
public:
    Player(int x, int y);
    void move();
};


#endif //HARAMBE_PLAYER_H
