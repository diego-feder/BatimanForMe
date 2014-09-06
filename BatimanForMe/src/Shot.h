#pragma once

#include "stdafx.h"

#include "DamageAbleEntity.h"


class Shot : public DamageAbleEntity
{
private:

    int shotSpeed;
    int type;
    int index;
public:

    Shot(int typ = 0, int spd = SHOT_SPEED,int dmg = 0, int x = PLAYER_START_X + SHOT_X, int = PLAYER_START_Y + SHOT_Y);
    ~Shot();
    void move();
    void attack();
    void print(BITMAP* pWhereToPrint);
    void isAvailable();
    int getShotSpeed();
    const int getSpriteIndex();
    void deleteShot();

};
