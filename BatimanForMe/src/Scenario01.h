#pragma once

#include "stdafx.h"

#include "BaseScenario.h"
#include "FakeJoker.h"

class Scenario01 : public BaseScenario
{
private:
    bool mapMove;
public:
	Scenario01(int startX = 100, int startY = 300);
	~Scenario01();

	void saveScenario01();
	void loadScenario01();
    void loadMap();
    void createRandomFakeJokers();

    void print(BITMAP* pWhereToPrint);
	void move();

    bool scenarioEnd();

	void execute();
};



