#include "BaseScenario.h"


BaseScenario::BaseScenario(int startX, int startY )
{
    pDamageAbleEntityList = new DamageAbleEntityList;
    pCharacterList = new CharacterList;
    playerStartX = startX;
    playerStartY = startY;
    X = 0;
}

BaseScenario::~BaseScenario()
{

}

void BaseScenario::attachTimer(Timer* pT)
{
    pAttachedTimer= pT;
}

Timer* BaseScenario::getAttachedTimer() const
{
    return pAttachedTimer;
}

void BaseScenario::attachPlayer(Player* pP)
{
    pAttachedPlayer = pP;
}

Player* BaseScenario::getAttachedPlayer() const
{
    return pAttachedPlayer;
}

DamageAbleEntityList* BaseScenario::getDamageAbleEntityList() const
{
    return pDamageAbleEntityList;
}

CharacterList* BaseScenario::getCharacterList() const
{
    return pCharacterList;
}

 int BaseScenario::getPlayerStartX() const
 {
     return playerStartX;
 }
 int BaseScenario::getPlayerStartY() const
 {
     return playerStartY;
 }

void BaseScenario::attachCollisionManager(CollisionManager* pCollisionManager)
{
    pAttachedCollisionManager = pCollisionManager;
}

bool BaseScenario::askCollisionCheckEnemyShotPlayer(Shot* pShot, Player* pPlayer)
{
    return pAttachedCollisionManager->collisionCheckEnemyShotPlayer(pShot, pPlayer);
}


void BaseScenario::pauseEvent()
{
        if (key[KEY_P])
        {
            pause = load_bitmap("img/paused.bmp", 0);
            draw_sprite(screen, pause, PAUSE_X, PAUSE_Y);
            rest(300);
            do
            {
                rest(50);
            }while(!key[KEY_P] && !key[KEY_ESC]);

            destroy_bitmap(pause);
            rest(100);
        }
}

void BaseScenario::collisionCheck()
{
    pAttachedCollisionManager->collisionCheckPlayerMap(pAttachedPlayer);
    if(!pAttachedPlayer->isBatarangAvailable())
    {
        pAttachedCollisionManager->collisionCheckShotCharacters();
    }
}

void BaseScenario::moveEntities()
{
    pAttachedPlayer->move();
    pDamageAbleEntityList->moveDamageAbleEntities();
}

void BaseScenario::charactersAttack()
{
    pAttachedPlayer->attack();
    pCharacterList->attackCharacters();
}

void BaseScenario::printEntities()
{
    print(buffer);
    pAttachedTimer->printTimer(buffer);
    pDamageAbleEntityList->printDamageAbleEntities(buffer);
    pAttachedPlayer->print(buffer);
}
