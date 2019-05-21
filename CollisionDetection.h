#ifndef HARAMBE_COLLISIONDETECTION_H
#define HARAMBE_COLLISIONDETECTION_H


#include "gameObjects/GameObject.h"

class CollisionDetection {
public:
    bool static check(GameObject *obj, GameObject *obj2);
};


#endif //HARAMBE_COLLISIONDETECTION_H
