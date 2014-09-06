#pragma once

#include"stdafx.h"

#include "DamageAbleEntity.h"
#include "List.h"

class DamageAbleEntityList: public List<DamageAbleEntity>
{
private:
public:
    DamageAbleEntityList();
    ~DamageAbleEntityList();
    void moveDamageAbleEntities();
    void attackDamageAbleEntities();
    void printDamageAbleEntities(BITMAP* pWhereToPrint);
    void moveCharacters();

};
