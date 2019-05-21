#ifndef HARAMBE_CROSSHAIR_H
#define HARAMBE_CROSSHAIR_H

#include "GameObject.h"

class Crosshair : public GameObject
{
private:
    int angle;
    int length;
    int x;
    int y;

public:
    Crosshair(int x, int y);
    ~Crosshair();
    void setAngle(int angle);
    void setLength(int l);
    void paint(QPainter* painter);
private:
    double degtorad(int deg);
    void move(uint64_t delta) override;
    short getBodyType() const override;
};


#endif //HARAMBE_CROSSHAIR_H
