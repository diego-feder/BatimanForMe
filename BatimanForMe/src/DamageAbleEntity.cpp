#include "DamageAbleEntity.h"


DamageAbleEntity::DamageAbleEntity()
{
    actualMask = maskVector[0];
}

DamageAbleEntity::DamageAbleEntity(int dmg,int x, int y ):
Entity(x,y)
{
    offsetX = x;
    damage = dmg;
}

DamageAbleEntity::~DamageAbleEntity()
{
}

void DamageAbleEntity::setDamage(const int value)
{
    damage = value;
}
const int DamageAbleEntity::getDamage() const
{
    return damage;
}

PMASK* DamageAbleEntity::getActualMask()
{
    return actualMask;
}

const int DamageAbleEntity::getSpriteIndex() const
{
    return spriteIndex;
}

void DamageAbleEntity::maskSelector()
{
    actualMask = maskVector[spriteIndex];
}

const int DamageAbleEntity::getOffsetX() const
{
    return offsetX;
}
