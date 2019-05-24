#include <QString>
#include "Obstacle.h"
#include <qDebug>
#include <QPainter>
#include <QMovie>

Obstacle::Obstacle(int x, int y) {
    this->x = x;
    this->y = y;
    this->width = 50;
    this->initialX = this->x;
    this->initialY = this->y;
    this->maxHorizontal = 15;
    this->maxVertical = 120;
    this->horizonalMultiplier = -.5;
    this->verticalMultiplier = -.7;
    this->movie = new QMovie("img/pokemon.gif");
    this->movie->setSpeed(75);
    this->movie->start();
    this->img = this->movie->currentImage();
}

void Obstacle::move(uint64_t delta) {
    auto steps = delta / 10;
    //qDebug() << delta;
    //qDebug() << steps;
    this->x += (int) (delta * this->horizonalMultiplier / 10);
    this->y += (int) (delta * this->verticalMultiplier / 10);

    // Ballon is moving left
    if (this->horizonalMultiplier < 0) {
        if (this->x < this->initialX - this->maxHorizontal) {
            this->horizonalMultiplier = .5;
        }
    }
        // Ballon is moving right
    else if (this->horizonalMultiplier > 0) {
        if (this->x > this->initialX) {
            this->horizonalMultiplier = -.5;
        }
    }

    // Ballon is moving up
    if (this->verticalMultiplier < 0) {
        if (this->y < this->initialY - this->maxVertical) {
            this->verticalMultiplier = .7;
        }
    }
        // Ballon is moving down
    else if (this->verticalMultiplier > 0) {
        if (this->y > this->initialY) {
            this->verticalMultiplier = -.7;
        }
    }
}

short Obstacle::getBodyType() const {
    return GameObject::KINEMATIC_BODY;
}

void Obstacle::onOutOfBound() {

}

void Obstacle::paint(QPainter *painter) {
    this->img = movie->currentImage();
    GameObject::paint(painter);
}
