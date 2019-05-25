#include <QPen>
#include <QPainter>
#include <cmath>
#include "Crosshair.h"

Crosshair::Crosshair(int x, int y) : x(x), y(y), angle(0), length(0)
{

}

void Crosshair::paint(QPainter* painter)
{
    QPen pen(QBrush(Qt::red), 4, Qt::DashLine, Qt::SquareCap, Qt::BevelJoin);

    // Point to start drawing from
    QPoint p1(this->x, this->y);

    // Use trigonometry to calculate the second point
    /*
     *     x1
     *    ----P2
     *    |  /
     * y1 | /
     *    |/
     *    P1
     */
    // Calculate angle at point P2 ("Wechselwinkel" between P1 and "floor")
    int tmpangle = this->angle;
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

void Crosshair::setLength(int l)
{
    this->length = l;
}

double Crosshair::degtorad(int deg)
{
    return deg * 3.14159/180;
}
