#include "DamageAbleEntityList.h"

DamageAbleEntityList::DamageAbleEntityList()
{
    pFirstElement = NULL;
    pLastElement = NULL;

}

DamageAbleEntityList::~DamageAbleEntityList()
{

}


void DamageAbleEntityList::moveDamageAbleEntities()
{
    Element<DamageAbleEntity>* pAux = pFirstElement;
    while(pAux)
    {
        pAux->getAttached()->move();
        pAux = pAux->getNextElement();
    }
}

void DamageAbleEntityList::printDamageAbleEntities(BITMAP* pWhereToPrint)
{
    Element<DamageAbleEntity>* pAux = pFirstElement;
    while(pAux)
    {
        pAux->getAttached()->print(pWhereToPrint);
        pAux = pAux->getNextElement();
    }
}
