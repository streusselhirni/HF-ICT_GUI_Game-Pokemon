#include "GameArea.h"
#include "gameObjects/Player.h"
#include "gameObjects/Obstacle.h"
#include "gameObjects/Shot.h"
#include "Thread.h"
#include "CollisionDetection.h"
#include "gameObjects/Crosshair.h"
#include <QImage>
#include <QPainter>
#include <random>
#include <QDebug>
#include <QSound>

GameArea::GameArea(QWidget *parent, int w, int h) : width(w), height(h) {
    this->backgroundImage = new QImage("img/background.jpg");
    this->lastMeasurement = 0;

    this->t = new Thread();
    connect(t, &Thread::refresh, this, &GameArea::next);
    t->start();
    this->player = nullptr;
    this->started = false;
    this->crosshair = new Crosshair(70, this->backgroundImage->scaledToWidth(this->width).height() - 180);
}

void GameArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawImage(0, 0, this->backgroundImage->scaledToWidth(this->width));

    if (!this->started) {return;}

    for (GameObject *g : this->gameObjects) {
        g->paint(&painter); // Shots are painted in Player::paint()
    }

    this->crosshair->paint(&painter);
}

GameArea::~GameArea() {
    delete this->backgroundImage;
    for (auto p : this->gameObjects) {
        delete p;
    }
    // delete this->player;
    delete this->crosshair;
}

void GameArea::next() {
    if (this->started) {
        auto           newMeasurement = this->measure();
        auto           delta          = newMeasurement - this->lastMeasurement;
        for (GameObject* g : this->gameObjects) {
            g->move(delta); // Shots are moved in Player::move()
        }

        this->player->checkShotsOutOfBounds(this);

        for (GameObject* g : this->gameObjects) {
            if (this->player->checkShotCollision(g)) {
                QSound::play("sound/capture.wav");
                emit this->gameFinished();
                break;
            }
        }

        this->lastMeasurement = newMeasurement;
    }

    this->update();
}

void GameArea::startGame() {
    this->player = new Player(10, this->backgroundImage->scaledToWidth(this->width).height() - 240);
    this->gameObjects.push_back(player);

    int x = 700 + (rand() % 18 * 10);
    int y = 200 + (rand() % 18 * 10);

    auto *obstacle = new Obstacle(x, y);

    this->gameObjects.push_back(obstacle);
    this->lastMeasurement = this->measure();
    this->started = true;
}

void GameArea::endGame() {
    this->started = false;
    for (auto p : this->gameObjects) {
        delete p;
    }
    this->gameObjects.clear();
    //delete this->player;
}

void GameArea::shoot(int speed, int angle) {
    this->player->shoot(speed, angle);
}

uint64_t GameArea::measure() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
    ).count();
}

void GameArea::angleChanged(int a) {
    this->crosshair->setAngle(a);
}

void GameArea::strengthChanged(int s) {
    this->crosshair->setLength(2 * s);
}
