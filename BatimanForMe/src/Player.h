#pragma once

#include "stdafx.h"
#include "Shot.h"
#include "Ranking.h"
#include "Character.h"
#include "BaseScenario.h"

class BaseScenario;


class Player : public Character
{
protected:

	string powerUp;
	int damageToTake;
	int score;
	int jumpSpriteIndex;
	int crouchSpriteIndex;
	bool movingBackwards;
	bool leftScreenLimit;
	char spriteString[20];
	string name;

	double collisionTime;

    bool jumping;
    bool onSolidGround;
    bool crouching;
    bool invulnerable;
    bool takingDamage;
    bool takingShot;
    int velocityX;
    int velocityY;

    Shot* pBatarang;
    bool shootAvailable;

    BaseScenario* pScenarioAttached;
    Ranking* pAttachedRanking;

	vector <BITMAP*> spriteWalk;
	vector <BITMAP*> jumpSprites;
	vector <BITMAP*> crouchSprites;
	vector <BITMAP*> spriteRoll;
	vector <BITMAP*> spriteHit;

    BITMAP* portrait;
    vector <BITMAP*> healthbar;

	vector <struct PMASK*> jumpSpritesMask;
	vector <struct PMASK*> rotatedJumpSpritesMask;
	vector <struct PMASK*> crouchSpritesMask;
	vector <struct PMASK*> rotatedCrouchSpritesMask;



public:
	Player(int s = 0, int h = MAX_HEALTH , int atk = 0, int dmg = 0, int x = 0, int y = 0, int vx = 0, int vy = 0);
	~Player();

	void savePlayer();
	void loadPlayer();

	void loadName();


    int getSpriteIndex() const;
    int getJumpSpriteIndex() const;

    vector<struct PMASK*>* getJumpSpritesMask();
	vector<struct PMASK*>* getRotatedJumpSpritesMask();

    int getVelocityX() const;
	void setVelocityX(int velocity);

	int getVelocityY() const;
	void setVelocityY(int velocity);

    int getScore();
    void setScore(int value);
    const int getHealth() const;

    void decreaseHealth();

    void increaseScore(const int points);

    Shot* getBatarang() const;

    void attachScenario(BaseScenario* pSc);
    void attachRanking (Ranking* pR);


    void attack();

    void enableJumpEvent();
    void disableJumpEvent();

    void enableSolidGroundEvent();
    void disableSolidGroundEvent();

    void enableShootAvailable();

    void enableInvulnerable();
    void disableInvulnerable();

    void enableTakingDamage(const int dmg);

    bool isJumping() const;
    bool isCrouching() const;
	bool isOnSolidGround() const;
    bool isMovingBackwards() const;
    bool isBatarangAvailable() const;
    bool isInvulnerable() const;
    bool isTakingDamage() const;

    void executeJump();
    void executeWalk();
    void executeShot();
    void executeCrouch();
    void executeDamage();
    void move();

    void maskSelector();

    void print(BITMAP* pWhereToPrint);

    void operator--();

};
