#pragma once

#include "stdafx.h"

#include "DamageAbleEntity.h"


class Character : public DamageAbleEntity {
protected:
	int health;
	int attackPower;
    int destX;
	int destY;

public:
    Character();
	Character(int h = MAX_HEALTH, int atk = 0, int dmg = 0, int x = 0, int y = 0);
	virtual ~Character();

    void setDestX(const int value);
	const int getDestX() const;
	void decreaseDestX(const int value);
    void setDestY(const int value);
	const int getDestY() const;

	virtual void setHealth(const int value);
	virtual const int getHealth() const;

	void setAttackPower(const int value);
	const int getAttackPower() const;


	virtual void move()  = 0;
	virtual void print(BITMAP* pWhereToPrint) = 0;
	virtual void attack() = 0;

	virtual void operator--(int);

    virtual void maskSelector();


};

