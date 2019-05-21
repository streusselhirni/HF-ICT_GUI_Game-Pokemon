//
// Created by Nicolas Haenni on 2019-05-11.
//

#ifndef HARAMBE_GAMEAREA_H
#define HARAMBE_GAMEAREA_H

#include <vector>
#include <QWidget>

class QImage;

class GameObject;

class Thread;

class GameArea : public QWidget {
Q_OBJECT;
private:
    QImage *backgroundImage;
    std::vector<GameObject *> gameObjects;
    Thread *t;
    int width;
    int height;
    uint64_t lastMeasurement{};
protected:
    void paintEvent(QPaintEvent *event) override;

    uint64_t measure();

public:
    explicit GameArea(QWidget *parent, int w, int h);

    ~GameArea() override;

    void startGame();

    void shoot(int speed, int angle);

public slots:

    void next();

signals:

    void gameFinished();
};


#endif //HARAMBE_GAMEAREA_H
