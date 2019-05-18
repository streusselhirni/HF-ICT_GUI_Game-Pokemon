#include "CollisionDetection.h"
#include <qDebug>

bool CollisionDetection::check(GameObject *obj, GameObject *obj2) {
    qDebug() << "Object 1:";
    qDebug() << "X:\t" << obj->getX();
    qDebug() << "Width:" << obj->getWidth();
    qDebug() << "Y: \t" << obj->getY();
    qDebug() << "Height:" << obj->getHeight();

    qDebug() << "Object 2:";
    qDebug() << "X:\t" << obj2->getX();
    qDebug() << "Width:" << obj2->getWidth();
    qDebug() << "Y: \t" << obj2->getY();
    qDebug() << "Height:" << obj2->getHeight();
    qDebug() << "_______________________";


    return false;
}
