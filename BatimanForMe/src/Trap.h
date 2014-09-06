#pragma once

#include "stdafx.h"
#include "DamageAbleEntity.h"
#include "BaseScenario.h"

class Trap : public DamageAbleEntity {
public:
	Trap(BaseScenario* pSc = NULL ,const int dmg = 1, int x = 250, int y = 200);
	virtual ~Trap();

    void print(BITMAP* pWhereToPrint);
    void move();

    void attachScenario(BaseScenario* pSc);

private:
    BaseScenario* pAttachedScenario;
};

