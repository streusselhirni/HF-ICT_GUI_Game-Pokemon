#include <QString>
#include <cmath>
#include "Shot.h"
#include <QPainter>

Shot::Shot(int x, int y, int speed, int angle) : speed(speed), angle(angle), t(0) {
    this->x = x;
    this->y = y;
    this->width = 30;
    this->movie = new QMovie("img/pokeball.gif");
    this->movie->setSpeed(50);
    this->movie->start();
    this->img = this->movie->currentImage();
    this->fired = false;
}

void Shot::move(uint64_t delta) {
    if (!this->fired) { return; }
    double rad = 3.1415926 / 180 * this->angle;
    auto dx = (int) this->speed / 3 * cos(rad) * this->t;
    auto dy = (int) this->speed / 3 * sin(rad) * this->t - (this->g / 2) * pow(this->t, 2);
    this->t += .1;
    this->x = this->x + dx / 2;
    this->y = this->y - dy / 2;
}

short Shot::getBodyType() const {
    return GameObject::KINEMATIC_BODY;
}

void Shot::setSpeed(int speed) {
    this->speed = speed;
}

void Shot::setAngle(int angle) {
    this->angle = angle;
}

void Shot::fire() {
    this->fired = true;
}

void Shot::paint(QPainter *painter) {
    if (this->fired) {
        this->img = movie->currentImage();
        GameObject::paint(painter);
    }
}

void Shot::onOutOfBound() {
    this->fired = false;
}
