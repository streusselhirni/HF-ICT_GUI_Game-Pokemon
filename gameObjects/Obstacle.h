#ifndef HARAMBE_OBSTACLE_H
#define HARAMBE_OBSTACLE_H


#include "GameObject.h"

class Obstacle: public GameObject
{
public:
    Obstacle(int x, int y);
    void move();
};


#endif //HARAMBE_OBSTACLE_H
