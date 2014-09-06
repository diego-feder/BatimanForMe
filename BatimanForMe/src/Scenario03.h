#pragma once

#include "stdafx.h"

#include "BaseScenario.h"
#include "Boss.h"


class Scenario03 : public BaseScenario
{
private:
    Boss* clayFace;
public:
	Scenario03(int startX = 100, int startY = PLAYER_SC02_Y);
	~Scenario03();

    void loadMap();

    Boss* getBoss();
    void createBoss();

    void print(BITMAP* pWhereToPrint);

    void move();

    bool scenarioEnd();

	void execute();

};

