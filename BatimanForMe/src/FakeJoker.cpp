#include "FakeJoker.h"

FakeJoker::FakeJoker(Player* pP, BaseScenario* pSc, int h, int atk, int dmg, int x, int y):
    Character(h, atk, dmg, x, y)
{
    aux = x;
    isBehind = false;
    shooting = false;
    attachPlayer(pP);
    attachScenario(pSc);
    spriteIndex = 0;

    loadSprites("sprites/fakeJoker/fakeJoker%d.bmp", 2,&spriteVector);
    createMasks(&spriteVector, &maskVector, &rotatedMaskVector);

    actualMask = maskVector[spriteIndex];

}

FakeJoker::~FakeJoker()
{
    int index = 0;
    for(index=0; index < spriteVector.size(); index++)
    {
        destroy_pmask(maskVector[index]);
        destroy_pmask(rotatedMaskVector[index]);
        destroy_bitmap(spriteVector[index]);
    }
}

void FakeJoker::attachPlayer(Player* pP)
{
    pAttachedPlayer = pP;
}

void FakeJoker::attachScenario(BaseScenario* pSc)
{
    pBaseScenarioAttached = pSc;
}


void FakeJoker::move()
{
    X = offsetX - pBaseScenarioAttached->getX();

    ((pAttachedPlayer->getX() > X))?(isBehind = true):(isBehind = false);

    maskSelector();
}

int i = 0;
void FakeJoker::attack()
{
    i++;
    if (i == 10)
    {
        shooting = true;
        spriteIndex = 1;
    }
    else
    {
        shooting = false;
        spriteIndex = 0;
    }
    if (i == 99)
    {
        i = 0;
    }

    if (shooting && ((this->getX() - pAttachedPlayer->getX()) < 500) && ((this->getX() - pAttachedPlayer->getX()) > -400)
                    && (!pAttachedPlayer->isCrouching()))
    {
           pAttachedPlayer->enableTakingDamage(attackPower);
    }
}

void FakeJoker::print(BITMAP* pWhereToPrint)
{

    if(isBehind)
    {
        draw_sprite_h_flip(pWhereToPrint, spriteVector[spriteIndex], X, Y);
    }
    else
    {
        draw_sprite(pWhereToPrint, spriteVector[spriteIndex], X, Y);
    }
}

void FakeJoker::executeDamage()
{

}

void FakeJoker::maskSelector()
{
    if(isBehind)
    {
        actualMask = rotatedMaskVector[spriteIndex];
    }
    else
    {
        actualMask = maskVector[spriteIndex];
    }
}




