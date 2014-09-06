#pragma once

#include "stdafx.h"

class Entity {
protected:
    vector<struct PMASK*> maskVector;
    vector<struct PMASK*> rotatedMaskVector;

    vector<BITMAP*> spriteVector;



    int ID;
	int X;
	int Y;

public:
    static int nextID;
    static int counter;

public:
    Entity();
    Entity(int x, int y);
    virtual ~Entity();

    bool newGame();

	void setX(const int value);
	const int getX() const;
	void decreaseX(const int value);
    void setY(const int value);
	const int getY() const;


	const int getID() const;
	const int getCounter() const;

	PMASK* getActualMask() const;

	virtual void print(BITMAP* pWhereToPrint) = 0;
	virtual void move() = 0;

	void createMasks( vector<BITMAP*>* pWhichVectorToMask, vector<PMASK*>* pDestinationMaskVector,vector<PMASK*>*  pDestinationRotatedMaskVector);
	void createMasks(vector<BITMAP*>* pWhichVectorToMask, vector<PMASK*>* pDestinationMaskVector);
	void createMasks(const char* nameBase, const int numberOfSprites, vector<PMASK*>* pDestinationMaskVector,vector<PMASK*>*  pDestinationRotatedMaskVector);
    void createMasks(const char* nameBase, const int numberOfSprites, vector<PMASK*>* pDestinationMaskVector);
    void loadSprites(const char* nameBase, const int numberOfSprites, vector<BITMAP*>* pWhichVectorToLoad);
    void loadSprites(const char* nameBase, vector<BITMAP*>* pWhichVectorToLoad);



	vector<BITMAP*>* getSpriteVector() ;
	vector<struct PMASK*>* getMaskVector();
	vector<struct PMASK*>* getRotatedMaskVector();

};

 //struct PMASK* mask;

    //int destX;
	//int destY;


	//const int getSpriteIndex() const;

	/*void setDestX(const int value);
	const int getDestX() const;
	void decreaseDestX(const int value);
	void setDestY(const int value);
	const int getDestY() const;*/
