//
// Created by Nicolas Haenni on 2019-05-11.
//

#ifndef HARAMBE_GAMEAREA_H
#define HARAMBE_GAMEAREA_H

#include <vector>
#include <QWidget>
#include "gameObjects/Player.h"

class QImage;

class GameObject;

class Thread;

class Crosshair;

class GameArea : public QWidget {
Q_OBJECT;
private:
    QImage *backgroundImage;
    std::vector<GameObject *> gameObjects;
    Crosshair* crosshair;
    Thread *t;
    int width;
    int height;
    int angle;
    uint64_t lastMeasurement{};
protected:
    Player *player;

    void paintEvent(QPaintEvent *event) override;

public:
    explicit GameArea(QWidget *parent, int w, int h);

    ~GameArea() override;

    void startGame();

    void endGame();

    void shoot(int speed, int angle);

    uint64_t measure();

public slots:

    void next();

    void angleChanged(int a);

    void strengthChanged(int s);

signals:

    void gameFinished();
};


#endif //HARAMBE_GAMEAREA_H
