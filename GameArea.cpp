#include "GameArea.h"
#include "gameObjects/Player.h"
#include "gameObjects/Obstacle.h"
#include "gameObjects/Shot.h"
#include "Thread.h"
#include <QImage>
#include <QPainter>
#include <QDebug>

GameArea::GameArea(QWidget* parent)
{
    this->backgroundImage = new QImage("img/background.jpg");

    // TODO: Remove this again, this is just for testing
    auto *player = new Player(10, this->backgroundImage->scaledToWidth(1200).height() - 200);
    auto* obstacle = new Obstacle(1000, 100);
    auto *shot = new Shot(400, 400, 50, 50);

    this->gameObjects.push_back(player);
    this->gameObjects.push_back(obstacle);
    this->gameObjects.push_back(shot);

    this->t = new Thread();
    connect(t, &Thread::refresh, this, &GameArea::next);
    t->start();
}

void GameArea::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, this->backgroundImage->scaledToWidth(1200));

    for (GameObject* g : this->gameObjects) {
        g->paint(&painter);
    }
}

GameArea::~GameArea()
{

}

void GameArea::next()
{
    qDebug() << "Next called";
}
