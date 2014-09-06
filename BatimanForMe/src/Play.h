#pragma once

#include "stdafx.h"
#include "Scenario01.h"
#include "Scenario02.h"
#include "Scenario03.h"
#include "SoundManager.h"
#include "Transitions.h"

class Play
{
private:
	int time;
	int scenarioNumber;

	Scenario01 objScenario01;
	Scenario02 objScenario02;
    Scenario03 objScenario03;
	Player objPlayer;
	CollisionManager objCollisionManager;
	SoundManager objSoundManager;
	Timer objTimer;
	Transitions objTransitions;
	Ranking objRanking;

public:
	Play();
	~Play();

	bool newGame();

	void savePlay();
    void loadPlay();
    void reLoadGame();

	void scenario01_init();
	void scenario02_init();
	void scenario03_init();
	void execute();

};

