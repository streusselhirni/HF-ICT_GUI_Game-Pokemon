#ifndef HARAMBE_PLAYER_H
#define HARAMBE_PLAYER_H

#include "GameObject.h"
#include "Shot.h"

class QPainter;

class Player : public GameObject {
private:
    static const int MAX_SHOTS = 5;

    Shot* shots[MAX_SHOTS];

    Shot *getShot(int x, int y, int speed, int angle) const;

    void moveShots(uint64_t delta);

    void paintShots(QPainter* painter);

public:
    Player(int x, int y);

    ~Player() override;

    void move(uint64_t delta) override;

    short getBodyType() const override;

    bool shoot(int speed, int angle);

    void paint(QPainter *painter) override;

    void onOutOfBound() override;

    void checkShotsOutOfBounds(QWidget* parent);

    bool checkShotCollision(GameObject* target);
};


#endif //HARAMBE_PLAYER_H
