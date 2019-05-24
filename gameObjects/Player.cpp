#include <QString>
#include "Player.h"

Player::Player(int x, int y) : GameObject(x, y, 150, new QMovie("img/trainer.gif")) {
    this->shot = new Shot(x, y, 0, 0);
}

void Player::move(uint64_t delta) {
    // do nothing
}

short Player::getBodyType() const {
    return GameObject::BODY_NONE;
}

void Player::shoot(int speed, int angle) {
    this->shot->t = 0;
    this->shot->setX(this->x + 30);
    this->shot->setY(this->y + 30);
    this->shot->setSpeed(speed);
    this->shot->setAngle(angle);
    this->shot->fire();
}

Shot *Player::getShot() const {
    return this->shot;
}

void Player::onOutOfBound() {

}
