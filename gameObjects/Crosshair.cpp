#include <QPen>
#include <QPainter>
#include <cmath>
#include "Crosshair.h"

Crosshair::Crosshair(int x, int y) : x(x), y(y), angle(45), length(100)
{

}

void Crosshair::paint(QPainter* painter)
{
    QPen pen(QBrush(Qt::red), 4, Qt::DashLine, Qt::SquareCap, Qt::BevelJoin);
    QPoint p1(this->x, this->y);

    int tmpangle = 180 - 90 - (90 - this->angle);
    int x1 = this->length*cos(degtorad(tmpangle));
    int y1 = this->length*sin(degtorad(tmpangle));

    QPoint p2(this->x + x1, this->y - y1);
    painter->setPen(pen);
    painter->drawLine(p1, p2);
}

void Crosshair::setAngle(int a)
{
    this->angle = a;
}

void Crosshair::move(uint64_t delta)
{
}

short Crosshair::getBodyType() const
{
    return GameObject::BODY_NONE;
}

void Crosshair::setLength(int l)
{
    this->length = l;
}

double Crosshair::degtorad(int deg)
{
    return deg * 3.14159/180;
}

Crosshair::~Crosshair() = default;