#pragma once

#include"stdafx.h"

#include "Character.h"
#include "Player.h"
#include "BaseScenario.h"

class BaseScenario;

class Goon : public Character
{
private:
    Player* pAttachedPlayer;
    BaseScenario* pBaseScenarioAttached;

    int leftBoundary;
    int rightBoundary;

    int aux;
    bool shotLocked;
    bool shooting;
    bool leftDirection;

    int shootingIndex;
    int dodgingIndex;

    Shot* pGoonShot;

    vector<BITMAP*> shootingSpriteVector;
    vector<PMASK*>  shootingMaskVector;
    vector<PMASK*>  rotatedShootingMaskVector;
public:
	Goon(Player* pP = NULL, BaseScenario* pSc = NULL ,int lb = 0, int rb = 1, int h = 1, int atk = 1, int dmg = 1, int x = 600, int y = PLAYER_START_Y);
	~Goon();
	void attachPlayer(Player* pP);
	void attachScenario(BaseScenario* pSc);

	void move();
	void attack();
	void print(BITMAP* pWhereToPrint);
	void maskSelector();

	void executeDamage();

};
