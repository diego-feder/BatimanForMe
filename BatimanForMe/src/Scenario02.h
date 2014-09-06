#pragma once

#include "stdafx.h"

#include "BaseScenario.h"
#include "Trap.h"
#include "Goon.h"

class Scenario02 : public BaseScenario
{
private:
    bool mapMove;
public:
	Scenario02(int startX = 100, int startY = 300);
	~Scenario02();

	void saveScenario02();
	void loadScenario02();

    void loadMap();

    void print(BITMAP* pWhereToPrint);
	void move();

    void createRandomTrapsGoons();

    bool scenarioEnd();

	void execute();
};
