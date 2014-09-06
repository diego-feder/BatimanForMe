#include "Scenario03.h"

Scenario03::Scenario03(int startX, int startY) :
    BaseScenario(startX, startY)
{
    X = 0;
}

Scenario03::~Scenario03()
{

}

Boss* Scenario03::getBoss()
{
    return clayFace;
}

void Scenario03::loadMap()
{
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    if(!buffer)
    {
         allegro_message("Unable to creat Buffer Bitmap.");
    }

    loadSprites("img/map03.bmp", &spriteVector);
    createMasks("img/map03_mask.bmp", 1, &maskVector);


}


void Scenario03::print(BITMAP* pWhereToPrint)
{
    blit(spriteVector[0], pWhereToPrint, X,0,0,0, spriteVector[0]->w, spriteVector[0]->h);
}


bool Scenario03::scenarioEnd()
{
    if (clayFace->getHealth() <= 0)
    {
        //chamar WIN.
        return true;
    }
    else if (pAttachedPlayer->getHealth() <= 0)
    {
        //chamar LOSE.
        return true;
    }
    else
    {
        return false;
    }
}

void Scenario03::execute()
{
    loadMap();

    getAttachedPlayer()->setX(PLAYER_START_X);
    getAttachedPlayer()->setDestX(PLAYER_START_X);
    getAttachedPlayer()->setY(PLAYER_SC02_Y);
    getAttachedPlayer()->setDestY(PLAYER_SC02_Y);

    clayFace->startThread();
    pAttachedTimer->stateTrue();
    while (!key[KEY_ESC])
    {
        moveEntities();
        pAttachedPlayer->attack();


        collisionCheck();

        printEntities();
        masked_blit(buffer, screen,0,0,0,0,buffer->w,buffer->h);

        pauseEvent();

        if (scenarioEnd())
            break;
        rest(REST_TIME);
    }
}

void Scenario03::createBoss()
{
    clayFace = createEntity<Boss,int,int,int,int,int>(15, 1 , 1, 740,220);
}

void Scenario03::move()
{
    //Esse mapa não se move
}
