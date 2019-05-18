#ifndef HARAMBE_COLLISIONDETECTION_H
#define HARAMBE_COLLISIONDETECTION_H


#include "GameObject.h"

class CollisionDetection {
public:
    bool check(GameObject *obj, GameObject *obj2);
};


#endif //HARAMBE_COLLISIONDETECTION_H
