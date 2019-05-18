//
// Created by Nicolas Haenni on 2019-05-11.
//

#ifndef HARAMBE_GAMEAREA_H
#define HARAMBE_GAMEAREA_H

#include <vector>
#include <QWidget>

class QImage;

class GameObject;

class GameArea: public QWidget
{
Q_OBJECT;
private:
    QImage *backgroundImage;
    std::vector<GameObject*> gameObjects;
protected:
    void paintEvent(QPaintEvent* event) override;
public:
    explicit GameArea(QWidget* parent = nullptr);
    ~GameArea() override;
};


#endif //HARAMBE_GAMEAREA_H
