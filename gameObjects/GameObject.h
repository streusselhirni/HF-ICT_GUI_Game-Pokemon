//
// Created by Nicolas Haenni on 2019-05-11.
//

#ifndef HARAMBE_GAMEOBJECT_H
#define HARAMBE_GAMEOBJECT_H

class QImage;

class QString;

class QPainter;

class GameObject
{
private:
    QImage *img;

protected:
    int x;
    int y;
    int width;

public:
    GameObject(int x, int y, const QString& imgPath, int width);
    virtual void move() = 0;
    void paint(QPainter* painter);
    int getX();
    int getY();
    void setX(int val);
    void setY(int val);
    int getWidth();
    int getHeight();
};


#endif //HARAMBE_GAMEOBJECT_H
