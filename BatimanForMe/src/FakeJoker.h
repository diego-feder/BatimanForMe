#pragma once

#include"stdafx.h"

#include "Character.h"
#include "Player.h"
#include "BaseScenario.h"

class BaseScenario;


class FakeJoker : public Character
{
private:
    Player* pAttachedPlayer;
    BaseScenario* pBaseScenarioAttached;
    int aux;
    bool isBehind;
    bool shooting;

public:
	FakeJoker(Player* pP = NULL, BaseScenario* pSc = NULL ,int h = 1, int atk = 1, int dmg = 1, int x = 600, int y = PLAYER_START_Y);
	~FakeJoker();
	void attachPlayer(Player* pP);
	void attachScenario(BaseScenario* pSc);

	void move();
	void attack();
	void print(BITMAP* pWhereToPrint);

	void maskSelector();

	void executeDamage();

};
