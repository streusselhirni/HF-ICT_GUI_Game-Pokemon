#ifndef HARAMBE_CROSSHAIR_H
#define HARAMBE_CROSSHAIR_H

#include "GameObject.h"

class Crosshair
{
private:
    int angle;
    int length;
    int x;
    int y;

public:
    Crosshair(int x, int y);
    void setAngle(int angle);
    void setLength(int l);
    void paint(QPainter* painter);
private:
    double degtorad(int deg);
};


#endif //HARAMBE_CROSSHAIR_H
