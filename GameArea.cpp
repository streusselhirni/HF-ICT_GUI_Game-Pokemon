#include "GameArea.h"
#include "gameObjects/Player.h"
#include "gameObjects/Obstacle.h"
#include "gameObjects/Shot.h"
#include "Thread.h"
#include <QImage>
#include <QPainter>
#include <random>
#include <QDebug>

GameArea::GameArea(QWidget* parent, int w, int h): width(w), height(h)
{
    this->backgroundImage = new QImage("img/background.jpg");

    this->t = new Thread();
    connect(t, &Thread::refresh, this, &GameArea::next);
    t->start();
    t->resume();
}

void GameArea::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, this->backgroundImage->scaledToWidth(this->width));

    for (GameObject* g : this->gameObjects) {
        g->paint(&painter);
    }
}

GameArea::~GameArea()
{
    delete this->backgroundImage;
    for (GameObject* g : this->gameObjects) {
        delete g;
    }
    t->pause();
    t->wait();
    delete this->t;
}

void GameArea::next()
{
    qDebug() << "Next";
    for(GameObject* g : this->gameObjects) {
        g->move();
    }
    this->update();
}

void GameArea::startGame()
{
    auto *player = new Player(10, this->backgroundImage->scaledToWidth(this->width).height() - 200);
    this->gameObjects.push_back(player);

    // TODO: Make these numbers random
    int x = 400;
    int y = 300;

    auto *obstacle = new Obstacle(x, y);

    this->gameObjects.push_back(obstacle);
}

void GameArea::shoot()
{

}
