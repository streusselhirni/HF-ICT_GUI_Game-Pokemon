#include "CollisionDetection.h"
#include <QDebug>

bool CollisionDetection::check(GameObject *obj, GameObject *obj2) {
    if (obj->getBodyType() == GameObject::BODY_NONE || obj2->getBodyType() == GameObject::BODY_NONE) { return false; }

    if (obj->getX() + obj->getWidth() > obj2->getX() && obj->getX() < obj2->getX()) {
        if (obj->getY() + obj->getHeight() > obj2->getY() && obj->getY() < obj2->getY()) {
            return true;
        }
    }

    if (obj2->getX() + obj2->getWidth() > obj->getX() && obj2->getX() < obj->getX()) {
        if (obj2->getY() + obj2->getHeight() > obj->getY() && obj2->getY() < obj->getY()) {
            return true;
        }
    }

    return false;
}

bool CollisionDetection::isOutOfBound(GameObject *obj, QWidget *widget) {
    return widget->size().width() < obj->getX() || widget->size().height() < obj->getY();
}
