#include <QString>
#include "Shot.h"

Shot::Shot(int x, int y, int speed, int angle) : GameObject(x, y, QString("img/poopy.png"), 70), speed(speed), angle(angle), t(0)
{

}

void Shot::move()
{

}
