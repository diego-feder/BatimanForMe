#pragma once

#include "stdafx.h"

#include "Entity.h"
#include "DamageAbleEntityList.h"
#include "CharacterList.h"
#include "Player.h"
#include "CollisionManager.h"
#include "Timer.h"

class DamageAbleEntityList;
class Player;
class CollisionManager;

class BaseScenario: public Entity
{
protected:
    BITMAP* buffer;
	BITMAP* pause;

	DamageAbleEntityList* pDamageAbleEntityList;
	CharacterList* pCharacterList;
	Player* pAttachedPlayer;
	CollisionManager* pAttachedCollisionManager;
	Timer* pAttachedTimer;

	int playerStartX;
	int playerStartY;

public:
    BaseScenario(int startX = 100, int startY = 300);
    virtual ~BaseScenario();

    void attachTimer(Timer* pT);
    Timer* getAttachedTimer() const;

	void attachPlayer(Player* pP);
	Player* getAttachedPlayer() const;

    DamageAbleEntityList* getDamageAbleEntityList() const;
    CharacterList* getCharacterList() const;

    int getPlayerStartX() const;
    int getPlayerStartY() const;

    void collisionCheck();

    void printEntities();
    void moveEntities();
    void charactersAttack();


    void attachCollisionManager(CollisionManager* pCollisionManager);
    bool askCollisionCheckEnemyShotPlayer(Shot* pShot, Player* pPlayer);

    template<class EntityType, class... ArgumentType>
    EntityType* createEntity(ArgumentType... arguments)
    {
        EntityType* pET = new EntityType(arguments...);
        pDamageAbleEntityList->include(static_cast<DamageAbleEntity*> (pET));

        /*Verifica se a entidade é do Tipo Character, se for a inclui na character list*/
        try
        {
            Character& pAux = dynamic_cast<Character&>(*pET);
            pCharacterList->includeCharacter(&pAux);
        }
        catch (const std::bad_cast& e)
        {
            //Nada a fazer caso ele não seja do tipo character
        }
        return pET;
    }

    void pauseEvent();
	virtual void execute() = 0;


};

