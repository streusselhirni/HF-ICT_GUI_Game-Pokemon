#include "GameArea.h"
#include "gameObjects/Player.h"
#include "gameObjects/Obstacle.h"
#include "gameObjects/Shot.h"
#include "Thread.h"
#include "CollisionDetection.h"
#include <QImage>
#include <QPainter>
#include <random>
#include <QDebug>

GameArea::GameArea(QWidget *parent, int w, int h) : width(w), height(h) {
    this->backgroundImage = new QImage("img/background.jpg");
    this->lastMeasurement = 0;

    this->t = new Thread();
    connect(t, &Thread::refresh, this, &GameArea::next);
    t->start();
}

void GameArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawImage(0, 0, this->backgroundImage->scaledToWidth(this->width));

    for (GameObject *g : this->gameObjects) {
        g->paint(&painter);
    }
}

GameArea::~GameArea() {
    delete this->backgroundImage;
    for (auto p : this->gameObjects) {
        delete p;
    }
}

void GameArea::next() {
    auto newMeasurement = this->measure();
    auto delta = newMeasurement - this->lastMeasurement;
    for (GameObject *g : this->gameObjects) {
        g->move(delta);
    }

    std::vector<GameObject *>::iterator iter;
    for (iter = this->gameObjects.begin(); iter != this->gameObjects.end();) {
        if (CollisionDetection::isOutOfBound((*iter), this)) {
            // This is not very efficient.
            iter = this->gameObjects.erase(iter);
        } else {
            ++iter;
        }
    }

    bool stop = false;
    for (int i = 0; i < this->gameObjects.size(); ++i) {
        auto g = this->gameObjects[i];
        for (int j = i + 1; j < this->gameObjects.size(); ++j) {
            auto g2 = this->gameObjects[j];
            if (CollisionDetection::check(g, g2)) {
                emit this->gameFinished();
                stop = true;
                break;
            }
        }
        if (stop) {
            break;
        }
    }

    this->lastMeasurement = newMeasurement;
    this->update();
}

void GameArea::startGame() {
    auto *player = new Player(10, this->backgroundImage->scaledToWidth(this->width).height() - 200);
    this->gameObjects.push_back(player);

    int x = 700 + (rand() % 15 * 10);
    int y = 200 + (rand() % 15 * 10);

    auto *obstacle = new Obstacle(x, y);

    this->gameObjects.push_back(obstacle);
    this->lastMeasurement = this->measure();
}

void GameArea::endGame() {
    for (auto p : this->gameObjects) {
        delete p;
    }
    this->gameObjects.clear();
}

void GameArea::shoot(int speed, int angle) {
    this->gameObjects.push_back(new Shot(50, 400, speed, angle));
}

uint64_t GameArea::measure() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
    ).count();
}
