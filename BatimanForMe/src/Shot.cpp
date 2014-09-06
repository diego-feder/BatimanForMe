#include "Shot.h"

Shot::Shot(int typ, int spd, int dmg, int x, int y) : DamageAbleEntity(dmg,x,y)
{
    shotSpeed = spd;
    type = typ;
    spriteIndex = 0;
    index = 0;

    if(type == 0)
        loadSprites("sprites/batman/shot%d.bmp",4, &spriteVector);

    if(type == 1)
        loadSprites("sprites/boss/clayShot.bmp",&spriteVector);

    if(type == 2)
        loadSprites("sprites/goon/goonshot%d.bmp",4,&spriteVector);

    createMasks(&spriteVector,&maskVector);
    actualMask = maskVector[0];
    //allegro_message("Constriui Shot");
}

Shot::~Shot()
{
    for(int i = 0; i < (int)spriteVector.size(); i++)
    {
        destroy_bitmap(spriteVector[i]);
        destroy_pmask(maskVector[i]);
    }
}

void Shot::attack()
{
}

void Shot::move()
{
    X += shotSpeed;

    if(spriteIndex < spriteVector.size())
    {
        if(type != 2)
        {
            spriteIndex++;
        }
        else
        {
            index++;
            if(index == 5)
            {
                index = 0;
                spriteIndex++;
            }
        }

        if (spriteIndex >= spriteVector.size())
        {
            spriteIndex = 0;
        }
    }

    maskSelector();
}

void Shot::print(BITMAP* pWhereToPrint)
{

    draw_sprite(pWhereToPrint, spriteVector[spriteIndex], X, Y);

    //draw_sprite_h_flip(pWhereToPrint, spriteVector[spriteIndex], X, Y);
}

const int Shot::getSpriteIndex()
{
    return spriteIndex;
}

int Shot::getShotSpeed()
{
    return shotSpeed;
}

void Shot::deleteShot()
{
    delete(this);
}
