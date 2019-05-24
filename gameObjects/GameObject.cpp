#include <QString>
#include <QPainter>
#include <QImage>
#include "GameObject.h"

GameObject::GameObject(int x, int y, const QString& imgPath, int width): x(x), y(y), width(width)
{
    this->img = QImage(imgPath);
}

GameObject::GameObject() = default;

void GameObject::paint(QPainter* painter)
{
    painter->drawImage(this->x, this->y, this->img.scaledToWidth(this->getWidth()));
}

int GameObject::getX() const
{
    return this->x;
}

int GameObject::getY() const
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

int GameObject::getWidth() const
{
    return this->width;
}

int GameObject::getHeight() const
{
    return this->img.scaledToWidth(this->width).height();
}

GameObject::~GameObject() = default;
