#include <QString>
#include <QSound>
#include "Player.h"
#include "../CollisionDetection.h"

Player::Player(int x, int y) : GameObject(x, y, 150, new QMovie("img/trainer.gif")) {
    for (int i = 0; i < Player::MAX_SHOTS; i++) {
        this->shots[i] = new Shot(0, 0, 0, 0);
    }
}

void Player::move(uint64_t delta) {
    this->moveShots(delta);
}

short Player::getBodyType() const {
    return GameObject::BODY_NONE;
}

bool Player::shoot(int speed, int angle) {
    return this->getShot(this->x + 30, this->y + 30, speed, angle) != nullptr;
}

Shot *Player::getShot(int x, int y, int speed, int angle) const {
    for (int i = 0; i < Player::MAX_SHOTS; i++) {
        if (!this->shots[i]->getFired()) {
            this->shots[i]->init(x, y, speed, angle, 0.1);
            return this->shots[i];
        }
    }
    return nullptr;
}

void Player::onOutOfBound() {

}

void Player::paintShots(QPainter* painter) {
    for (int i = 0; i < Player::MAX_SHOTS; i++){
        this->shots[i]->paint(painter);
    }
}

void Player::moveShots(uint64_t delta) {
    for (int i = 0; i < Player::MAX_SHOTS; i++){
        this->shots[i]->move(delta);
    }
}

void Player::checkShotsOutOfBounds(QWidget* parent) {
    for (int i = 0; i < Player::MAX_SHOTS; i++) {
        if (CollisionDetection::isOutOfBound(this->shots[i], parent)) {
            this->shots[i]->onOutOfBound();
        }
    }
}

bool Player::checkShotCollision(GameObject* target) {
    for (int i = 0; i < Player::MAX_SHOTS; i++) {
        if (CollisionDetection::check(this->shots[i], target)) {
            return true;
        }
    }

    return false;
}

void Player::paint(QPainter* painter) {
    GameObject::paint(painter);
    this->paintShots(painter);
}
