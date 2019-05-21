#include <QString>
#include "Player.h"

Player::Player(int x, int y): GameObject(x, y, QString("img/gorilla.png"), 150)
{

}

void Player::move(uint64_t delta)
{
    // do nothing
}

short Player::getBodyType() const {
    return GameObject::BODY_NONE;
}
