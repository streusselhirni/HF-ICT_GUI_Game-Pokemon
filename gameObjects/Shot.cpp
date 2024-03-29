#include <QString>
#include <cmath>
#include "Shot.h"
#include <QPainter>

Shot::Shot(int x, int y, int speed, int angle)
        : GameObject(x, y, 50, new QMovie("img/pokeball.gif"), 50),
          speed(speed),
          angle(angle),
          rotation(0),
          t(0) {
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
    this->rotation += 20;
}

short Shot::getBodyType() const {
    return GameObject::KINEMATIC_BODY;
}

void Shot::paint(QPainter *painter) {
    if (this->fired) {
        QTransform transform;
        transform.translate(this->x + this->getWidth()/2, this->y + this->getHeight()/2);
        transform.rotate(this->rotation);
        transform.translate(-(this->x + this->getWidth()/2), -(this->y + this->getHeight()/2));

        painter->setTransform(transform);
        if (this->movie != nullptr) {
            this->img = movie->currentImage();
        }
        painter->drawImage(this->x, this->y, this->img.scaledToWidth(this->getWidth()));
        painter->resetTransform();
    }
}

void Shot::onOutOfBound() {
    this->fired = false;
}

void Shot::init(int x, int y, int s, int a, double time) {
    this->x = x;
    this->y = y;
    this->speed = s;
    this->angle = a;
    this->t = time;
    this->fired = true;
}

bool Shot::getFired() {
    return this->fired;
}
