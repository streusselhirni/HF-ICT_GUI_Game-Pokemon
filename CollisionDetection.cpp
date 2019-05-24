#include "CollisionDetection.h"
#include <QDebug>
#include <cmath>

bool CollisionDetection::check(GameObject *obj, GameObject *obj2) {
    if (obj->getBodyType() == GameObject::BODY_NONE || obj2->getBodyType() == GameObject::BODY_NONE) { return false; }

    auto objX = obj->getX() + (obj->getWidth() / 2);
    auto objY = obj->getY() + (obj->getHeight() / 2);
    auto objRad = ((obj->getHeight() / 2) + (obj->getWidth() / 2)) / 2;

    auto obj2X = obj2->getX() + (obj2->getWidth() / 2);
    auto obj2Y = obj2->getY() + (obj2->getHeight() / 2);
    auto obj2Rad = ((obj2->getHeight() / 2) + (obj2->getWidth() / 2)) / 2;

    auto distanceY = abs(objY - obj2Y);
    auto distanceX = abs(objX - obj2X);

    auto hypotenuse = sqrt(pow(distanceY, 2) + pow(distanceX, 2));

    return hypotenuse < objRad + obj2Rad;
}

bool CollisionDetection::isOutOfBound(GameObject *obj, QWidget *widget) {
    return widget->size().width() < obj->getX() || widget->size().height() < obj->getY();
}
