#ifndef HARAMBE_COLLISIONDETECTION_H
#define HARAMBE_COLLISIONDETECTION_H


#include <QWidget>
#include "gameObjects/GameObject.h"

class CollisionDetection {
public:
    bool static check(GameObject *obj, GameObject *obj2);
    bool static isOutOfBound(GameObject *obj, QWidget *widget);
};


#endif //HARAMBE_COLLISIONDETECTION_H
