
#ifndef HARAMBE_GAMEOBJECT_H
#define HARAMBE_GAMEOBJECT_H

#include <stdint.h>
#include <QImage>

class QString;

class QPainter;

class GameObject {

protected:
    QImage img;
    int x;
    int y;
    int width;

public:
    short static const BODY_NONE = 0;
    short static const STATIC_BODY = 1;
    short static const DYNAMIC_BODY = 2;
    short static const KINEMATIC_BODY = 3;

    GameObject(int x, int y, const QString &imgPath, int width);

    GameObject();

    virtual ~GameObject();

    virtual void move(uint64_t delta) = 0;

    virtual void paint(QPainter *painter);

    int getX() const;

    int getY() const;

    void setX(int val);

    void setY(int val);

    int getWidth() const;

    int getHeight() const;

    virtual short getBodyType() const = 0;

    virtual void onOutOfBound() = 0;
};


#endif //HARAMBE_GAMEOBJECT_H
