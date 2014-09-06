#include "CharacterList.h"


CharacterList::CharacterList()
{

}

CharacterList::~CharacterList()
{
    list<Character*>::iterator it = L1.begin();

    while(it != L1.end())
    {
        delete (*it);
        it++;
    }
    L1.clear();
}

void CharacterList::includeCharacter(Character* pCharacter)
{
    (pCharacter)?(L1.push_back(pCharacter)) : (allegro_message("Null Character pointer!"));
}

void CharacterList::excludeCharacter(const int position)
{
    int index;

    for(it = L1.begin(), index = 0;index < position; index++, it++);
    L1.erase(it);
}

void CharacterList::excludeCharacter(Character* pCharacter)
{
    L1.remove(pCharacter);
}

Character* CharacterList::at(const int position)
{
    int index;

    for(it = L1.begin(), index = 0;index < position; index++, it++);
    return (*it);
}

const int CharacterList::size() const
{
    return L1.size();
}

void CharacterList::moveCharacters()
{
    it = L1.begin();

    while(it != L1.end())
    {
        (*it)->move();
        it++;
    }
}

void CharacterList::attackCharacters()
{
    it = L1.begin();
    while(it != L1.end())
    {
        (*it)->attack();
        it++;
    }
}
