#include "Entity.h"


int Entity::nextID = 0;
int Entity::counter  = 0;

Entity::Entity()
{

}

Entity::Entity(int x = 0, int y = 0)
{
    Entity::counter++;
    ID = Entity::nextID;
    Entity::nextID++;
    X = x;
    Y = y;

}

Entity::~Entity()
{
    Entity::nextID--;
}

bool Entity::newGame()
{
    string strGame;
    ifstream filePlay ("files/play.txt");
    if(filePlay.is_open())
    {
        getline(filePlay, strGame);
        filePlay.close();
    }

    if (strGame.compare("New") == 0)
        return true;
    else
        return false;
}


void Entity::setX(const int value)
{
    X = value;
}

const int Entity::getX() const
{
    return X;
}

void Entity::decreaseX(const int value)
{
    X -= value;
}


void Entity::setY(const int value)
{
    Y = value;
}

const int Entity::getY() const
{
    return Y;
}

const int Entity::getID() const
{
    return ID;
}

const int Entity::getCounter() const
{
    return counter;
}

vector<BITMAP*>* Entity::getSpriteVector()
{
    return &spriteVector;
}

vector<struct PMASK*>* Entity::getMaskVector()
{
    return &maskVector;
}

vector<struct PMASK*>* Entity::getRotatedMaskVector()
{
    return &rotatedMaskVector;
}


void Entity::loadSprites(const char* nameBase, const int numberOfSprites, vector<BITMAP*>* pWhichVectorToLoad)
{
    char spriteString[40];


    for(int i = 0; i < numberOfSprites; i++)
    {
        sprintf(spriteString,nameBase, i); //FUNCAO LOAD SPRITES
        pWhichVectorToLoad->push_back(load_bitmap(spriteString, 0));
        if(!pWhichVectorToLoad->at(i))
        {
            allegro_message("Unable to load sprite Bitmap.");
        }
    }

}

void Entity::loadSprites(const char* nameBase, vector<BITMAP*>* pWhichVectorToLoad)
{
    pWhichVectorToLoad->push_back(load_bitmap(nameBase, 0));
    if(!pWhichVectorToLoad->at(0))
    {
        allegro_message("Unable to load sprite Bitmap.");
    }

}

void Entity::createMasks(vector<BITMAP*>* pWhichVectorToMask, vector<PMASK*>* pDestinationMaskVector)
{
    for(int i = 0; i < pWhichVectorToMask->size(); i++)
    {
        pDestinationMaskVector->push_back(create_allegro_pmask(pWhichVectorToMask->at(i)));
    }

}
void Entity::createMasks(vector<BITMAP*>* pWhichVectorToMask, vector<PMASK*>* pDestinationMaskVector,vector<PMASK*>*  pDestinationRotatedMaskVector)
{
    BITMAP* temporaryBuffer;
    struct PMASK* temporaryPmask;
    for(int i = 0; i < pWhichVectorToMask->size(); i++)
    {
        temporaryBuffer = create_bitmap(pWhichVectorToMask->at(i)->w, pWhichVectorToMask->at(i)->h);
        clear_to_color(temporaryBuffer, makecol(255, 0, 255));
        draw_sprite_h_flip(temporaryBuffer, pWhichVectorToMask->at(i), 0, 0);
        temporaryPmask = create_allegro_pmask(temporaryBuffer);
        pDestinationRotatedMaskVector->push_back(temporaryPmask);
        pDestinationMaskVector->push_back(create_allegro_pmask(pWhichVectorToMask->at(i)));
    }
    destroy_bitmap(temporaryBuffer);
}



void Entity::createMasks(const char* nameBase,const int numberOfSprites, vector<PMASK*>* pDestinationMaskVector,vector<PMASK*>*  pDestinationRotatedMaskVector)
{
    char temporaryString[40];
    BITMAP* temporaryBuffer;
    BITMAP* temporaryBuffer2;
    struct PMASK* temporaryPmask;

    for(int i = 0; i < numberOfSprites; i++)
    {
        sprintf(temporaryString,nameBase, i);
        if(!(temporaryBuffer2 = load_bitmap(temporaryString, 0)))
        {
            allegro_message("Error loading Bitmap, in: createMasks()");
        }

        temporaryBuffer = create_bitmap(temporaryBuffer2->w, temporaryBuffer2->h);
        clear_to_color(temporaryBuffer, makecol(255, 0, 255));
        draw_sprite_h_flip(temporaryBuffer, temporaryBuffer2,0, 0);
        temporaryPmask = create_allegro_pmask(temporaryBuffer);
        pDestinationRotatedMaskVector->push_back(temporaryPmask);
        pDestinationMaskVector->push_back(create_allegro_pmask(temporaryBuffer2));
        destroy_bitmap(temporaryBuffer);
        destroy_bitmap(temporaryBuffer2);
    }
}

void Entity::createMasks(const char* nameBase, const int numberOfSprites, vector<PMASK*>* pDestinationMaskVector)
{
    char temporaryString[40];
    for(int i = 0; i < numberOfSprites; i++)
    {
        sprintf(temporaryString,nameBase, i);
        pDestinationMaskVector->push_back(create_allegro_pmask(load_bitmap(temporaryString,0)));
    }

}

