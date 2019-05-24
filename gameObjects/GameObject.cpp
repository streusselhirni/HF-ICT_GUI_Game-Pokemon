#include <QString>
#include <QPainter>
#include <QImage>
#include "GameObject.h"

GameObject::GameObject(int x, int y, const QString &imgPath, int width) : x(x), y(y), width(width) {
    this->movie = nullptr;
    this->img = QImage(imgPath);
}

GameObject::GameObject(int x, int y, int width, QMovie *movie, int movieSpeed) : x(x), y(y), width(width) {
    this->movie = movie;
    this->movie->setSpeed(movieSpeed);
    this->movie->start();
    this->img = movie->currentImage();
}

GameObject::GameObject(int x, int y, int width, QMovie *movie) : x(x), y(y), width(width) {
    this->movie = movie;
    this->movie->start();
    this->img = movie->currentImage();
}

GameObject::GameObject() = default;

void GameObject::paint(QPainter *painter) {
    if (this->movie != nullptr) {
        this->img = movie->currentImage();
    }
    painter->drawImage(this->x, this->y, this->img.scaledToWidth(this->getWidth()));
}

int GameObject::getX() const {
    return this->x;
}

int GameObject::getY() const {
    return this->y;
}

void GameObject::setX(int val) {
    this->x = val;
}

void GameObject::setY(int val) {
    this->y = val;
}

int GameObject::getWidth() const {
    return this->width;
}

int GameObject::getHeight() const {
    return this->img.scaledToWidth(this->width).height();
}

GameObject::~GameObject() = default;
