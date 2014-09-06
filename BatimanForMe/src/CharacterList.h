#pragma once

#include"stdafx.h"

#include "Character.h"


class CharacterList{
public:
	CharacterList();
	~CharacterList();
	void includeCharacter(Character* pCharacter);
	void excludeCharacter(const int position);
	void excludeCharacter(Character* pCharacter);

	const int size() const;
	Character* at(const int position);

	void listCharacter();
	//void printCharact(BITMAP* pWhereToPrint);
	void moveCharacters();
	void attackCharacters();
private:
	list<Character*> L1;
	list<Character*>::iterator it;

	//Scenario01* pAttachedScneario;
};

