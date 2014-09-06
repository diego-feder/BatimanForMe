#pragma once

#include "stdafx.h"

#include "Shot.h"
#include "Character.h"
#include "Player.h"
#include "Timer.h"
#include "Thread.h"
#include "Boss.h"


class Boss :  public Character, public Thread
{
private:
    int velX;

    bool movingBackwards;
    char spriteString[20];

    int r1, r2;
    int i;
    int indx = 0;

    Shot* pClayShot;
    bool shootAvailable;
    bool sliding;
    bool attacking;
    bool dir;

    BaseScenario* pAttachedScenario;

    vector<BITMAP*> spriteWalk;
    vector<BITMAP*> spriteSlide;
    vector<PMASK*> maskWalkVector;
    vector<PMASK*> rotatedMaskWalkVector;
    vector<PMASK*> maskSpriteSlide;
    vector<PMASK*> rotatedMaskSpriteSlide;

    BITMAP* portrait;
    vector <BITMAP*> healthbar;

    Player* pAttachedPlayer;
    Timer* pAttachedTimer;

    DWORD threadMemberFunction();

public:
	Boss(int h = 15 , int atk = 0, int dmg = 0, int x = 0, int y = 0);
	~Boss();

    void attachPlayer(Player* pP);
    void attachTimer(Timer* pT);


    bool isMovingBackwards() const;

    void roll();
    void slide();
	void move();
	void attack();

	void print(BITMAP* pWhereToPrint);

	void executeShot();

	void maskSelector();

	void attachScenario(BaseScenario* pScenario);

    void decreaseHealth();
    const int getHealth() const;
	void setHealth(const int value);
};
