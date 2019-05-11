#include <QString>
#include "Shot.h"

Shot::Shot(int x, int y, int speed, int angle) : GameObject(x, y, QString("img/banana"), 40), speed(speed), angle(angle), t(0)
{

}

void Shot::move()
{

}
