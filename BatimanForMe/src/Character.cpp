#include "Character.h"

//Construtora inicializa os atributos.
Character::Character(int h, int atk, int dmg, int x, int y) :
DamageAbleEntity(dmg,x,y)
{
    health = h;
    attackPower = atk;
}

Character::~Character()
{

}

void Character::setDestX(const int value)
{
    destX = value;
}

const int Character::getDestX() const
{
    return destX;
}

void Character::decreaseDestX(const int value)
{
    destX -= value;
}

void Character::setDestY(const int value)
{
    destY = value;
}

const int Character::getDestY() const
{
    return destY;
}


void Character::setHealth(const int value)
{
    health = value;
}

const int Character::getHealth() const
{
    return health;
}

void Character::setAttackPower(const int value)
{
    attackPower = value;
}

const int Character::getAttackPower() const
{
    return attackPower;
}

/*bool Character::isTakingDamage() const
{
    return takingDamage;
}

void Character::enableTakingDamage(const int dmg)
{
    takingDamage = true;
    damageToTake = dmg;
}*/

void Character::operator--(int)
{
    health--;
}

void Character::maskSelector()
{
    spriteVector[spriteIndex];
}
