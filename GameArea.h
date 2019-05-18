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

class GameArea: public QWidget
{
Q_OBJECT;
private:
    QImage *backgroundImage;
    std::vector<GameObject*> gameObjects;
    Thread* t;
    int width;
    int height;
protected:
    void paintEvent(QPaintEvent* event) override;
public:
    explicit GameArea(QWidget* parent, int w, int h);
    ~GameArea() override;
public slots:
    void next();
};


#endif //HARAMBE_GAMEAREA_H
