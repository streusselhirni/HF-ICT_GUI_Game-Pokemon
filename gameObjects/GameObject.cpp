#include <QString>
#include <QImage>
#include "GameObject.h"

GameObject::GameObject(int x, int y, const QString& imgPath, int width): x(x), y(y)
{
    this->img = new QImage(imgPath);
}

void GameObject::paint(QPainter* painter)
{

}

int GameObject::getX()
{
    return this->x;
}

int GameObject::getY()
{
    return this->y;
}

void GameObject::setX(int val)
{
    this->x = val;
}

void GameObject::setY(int val)
{
    this->y = val;
}

int GameObject::getWidth()
{
    return this->img->width();
}

int GameObject::getHeight()
{
    return this->img->height();
}
