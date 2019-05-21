#ifndef HARAMBE_PLAYER_H
#define HARAMBE_PLAYER_H

#include "GameObject.h"
#include "Shot.h"

class Player : public GameObject {
private:
    Shot *shot;
public:
    Player(int x, int y);

    void move(uint64_t delta) override;

    short getBodyType() const override;

    void shoot(int speed, int angle);

    Shot *getShot() const;

    void onOutOfBound() override;
};


#endif //HARAMBE_PLAYER_H
