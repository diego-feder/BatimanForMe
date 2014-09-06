#pragma once

#include "stdafx.h"

#include "Entity.h"

class DamageAbleEntity: public Entity {

protected:
    int damage;
    int offsetX;
    //int offsetY;

    int spriteIndex;

    PMASK* actualMask;
public:
    DamageAbleEntity();
    DamageAbleEntity(const int dmg, int x, int y);
    virtual ~DamageAbleEntity();

	void setDamage(const int value);
	const int getDamage() const;

    const int getSpriteIndex() const;
    PMASK* getActualMask();

	virtual void print(BITMAP* pWhereToPrint) = 0;
	virtual void move() = 0;
	virtual void maskSelector();

	const int getOffsetX() const;
};




