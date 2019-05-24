#ifndef HARAMBE_OBSTACLE_H
#define HARAMBE_OBSTACLE_H


#include <QMovie>
#include "GameObject.h"

class Obstacle : public GameObject {
private:
    int maxHorizontal;
    float horizonalMultiplier;
    int maxVertical;
    float verticalMultiplier;
    int initialX;
    int initialY;
    QMovie *movie;
public:
    Obstacle(int x, int y);

    void move(uint64_t delta) override;

    void paint(QPainter *painter) override;

    short getBodyType() const override;

    void onOutOfBound() override;
};


#endif //HARAMBE_OBSTACLE_H
