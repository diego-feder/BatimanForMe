#include "Trap.h"

Trap::Trap(BaseScenario* pSc,const int dmg, int x, int y ):
    DamageAbleEntity(dmg, x, y)
{
    pAttachedScenario = pSc;

    loadSprites("sprites/trap/trap0.bmp",&spriteVector);
    createMasks(&spriteVector, &maskVector);
    spriteIndex = 0;
    maskSelector();
}

Trap::~Trap()
{

}

void Trap::move()
{
     X = offsetX - pAttachedScenario->getX();
}

void Trap::print(BITMAP* pWhereToPrint)
{
    draw_sprite(pWhereToPrint, spriteVector[0], X, Y);
}


