#include "Goon.h"

Goon::Goon(Player* pP, BaseScenario* pSc,int lb, int rb, int h, int atk, int dmg, int x, int y):
    Character(h, atk, dmg, x, y)
{
    rightBoundary = rb;
    leftBoundary = lb;
    aux = x;
    //offsetX = x;
    shooting = false;
    leftDirection = true;
    attachPlayer(pP);
    attachScenario(pSc);
    spriteIndex = 0;
    shootingIndex = 0;
    shooting = false;
    shotLocked = false;
    /*spriteVector.push_back(load_bitmap("sprites/fakeJoker0.bmp", 0)); //0
    maskVector.push_back(create_allegro_pmask(spriteVector[0]));
    spriteVector.push_back(load_bitmap("sprites/fakeJoker1.bmp", 0)); //1
    maskVector.push_back(create_allegro_pmask(spriteVector[1]));*/

    loadSprites("sprites/goon/goon%d.bmp", 10,&spriteVector);
    createMasks(&spriteVector, &maskVector, &rotatedMaskVector);

    loadSprites("sprites/goon/goonshooting%d.bmp", 4, &shootingSpriteVector);
    createMasks(&shootingSpriteVector,&shootingMaskVector,&rotatedShootingMaskVector);


}

Goon::~Goon()
{
    int index = 0;
    for(index=0; index < spriteVector.size(); index++)
    {
        destroy_pmask(maskVector[index]);
        destroy_pmask(rotatedMaskVector[index]);
        destroy_bitmap(spriteVector[index]);
    }
}

void Goon::attachPlayer(Player* pP)
{
    pAttachedPlayer = pP;
}

void Goon::attachScenario(BaseScenario* pSc)
{
    pBaseScenarioAttached = pSc;
}


void Goon::move()
{
//    executeShot();

    if(shooting)
    {
        shootingIndex++;
        if(shootingIndex >= shootingSpriteVector.size())
        {
            spriteIndex = 0;
            shooting = false;
        }
    }
    else
    {
        spriteIndex++;
        if(leftDirection)
        {
            offsetX -= 14;
        }
        else
        {
            offsetX += 14;
        }

        if(spriteIndex >= spriteVector.size())
        {
            spriteIndex = 1;
        }
    }

    if(offsetX <= leftBoundary)
    {
        leftDirection = false;
    }
    else if(offsetX >= rightBoundary)
    {
        leftDirection = true;
    }

    maskSelector();
    X = offsetX - pBaseScenarioAttached->getX();
}

void Goon::attack()
{
    if(shotLocked)
    {
        pGoonShot->move();
        if((pGoonShot->getX() < (X - 600))||pBaseScenarioAttached->askCollisionCheckEnemyShotPlayer(pGoonShot,pAttachedPlayer))
        {
            shotLocked = false;
            pGoonShot->deleteShot();
        }
    }
    else
    {
        if((pAttachedPlayer->getX() + pBaseScenarioAttached->getX() >= offsetX - 600)&&!shotLocked)
        {
            pGoonShot= new Shot(2,-SHOT_SPEED, this->attackPower,this->X, this->Y-5);
            shotLocked = true;
            shooting = true;
            shootingIndex = 0;
        }
    }
}

void Goon::print(BITMAP* pWhereToPrint)
{
    if(!shooting)
    {
        if(!leftDirection)
        {
            draw_sprite_h_flip(pWhereToPrint, spriteVector[spriteIndex], X, Y);
        }
        else
        {
            draw_sprite(pWhereToPrint, spriteVector[spriteIndex], X, Y);
        }

    }
    else
    {
        draw_sprite(pWhereToPrint, shootingSpriteVector[shootingIndex], X, Y);
    }

    if(shotLocked)
    {
        pGoonShot->print(pWhereToPrint);
    }

    //draw_allegro_pmask(actualMask,pWhereToPrint,X,Y,0);
}

void Goon::executeDamage()
{

}

void Goon::maskSelector()
{
    if(!shooting)
    {
        if(!leftDirection)
        {
            actualMask = rotatedMaskVector[spriteIndex];
            //draw_sprite_h_flip(pWhereToPrint, spriteVector[spriteIndex], X, Y);
            //allegro_message("1");
        }
        else
        {
            actualMask = maskVector[spriteIndex];
            //draw_sprite(pWhereToPrint, spriteVector[spriteIndex], X, Y);
            //allegro_message("2");
        }

    }
    else
    {
        shootingMaskVector[shootingIndex];
        //allegro_message("3");
        //draw_sprite(pWhereToPrint, shootingSpriteVector[shootingIndex], X, Y);
    }

}



