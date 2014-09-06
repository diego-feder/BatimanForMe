#include "Scenario02.h"


Scenario02::Scenario02(int startX, int startY) :
BaseScenario(startX, startY)
{
    X = 0;
    mapMove = true;

    if (!newGame())
        loadScenario02();

    loadMap();

}

Scenario02::~Scenario02()
{
    saveScenario02();
}

void Scenario02::saveScenario02()
{
    ofstream myfile ("bin/scenario02.bin", ios::trunc);
    if (myfile.is_open())
    {
        myfile << X << endl;
        myfile.close();
    }
}

void Scenario02::loadScenario02()
{
    string str;
    ifstream myfile ("bin/scenario02.bin");
    if(myfile.is_open())
    {
        getline(myfile, str);
        X = atoi(str.c_str());
    }
    myfile.close();
}

void Scenario02::loadMap()
{
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    if(!buffer)
    {
         allegro_message("Unable to creat Buffer Bitmap.");
    }

    loadSprites("img/map02.bmp", &spriteVector);
    createMasks("img/map02_mask.bmp", 1, &maskVector);

}


void Scenario02::print(BITMAP* pWhereToPrint)
{
    blit(spriteVector[0], pWhereToPrint, X,0,0,0, spriteVector[0]->w, spriteVector[0]->h);
}

void Scenario02::move()
{
        mapMove = true;
        if (X >= SCENARIO02_RIGHTBORDER)
        {
            mapMove = false;
        }

        if ((pAttachedPlayer->getX()) >= (((SCREEN_W)/2) - 100) && mapMove)
        {

           if(pAttachedPlayer->getVelocityX() > 0)
            {
                pAttachedPlayer->decreaseDestX(SPEED_PLAYER_X);
                pAttachedPlayer->decreaseX(SPEED_PLAYER_X);
                X += SPEED_PLAYER_X;
            }

        }

}

bool Scenario02::scenarioEnd()
{
    if (pAttachedPlayer->getX() >= SCENARIO02_END_LENGHT || pAttachedPlayer->getHealth() <= 0)
        return true;

    return false;

}

 void Scenario02::createRandomTrapsGoons()
 {
     int n = 500;
     for(int index = 0; index < 4; index++ )
     {
         createEntity<Trap, BaseScenario*, int, int, int>(static_cast<BaseScenario*>(this), 1, n, 285);
         createEntity<Goon, Player*, BaseScenario*, int, int, int, int, int>(pAttachedPlayer, static_cast<BaseScenario*>(this), n+100, n+600, 3,2,2, n+500, 212);
         n += 600;
     }

 }

void Scenario02::execute()
{

    loadMap();

    getAttachedPlayer()->setX(PLAYER_START_X);
    getAttachedPlayer()->setDestX(PLAYER_START_X);
    getAttachedPlayer()->setY(PLAYER_SC02_Y);
    getAttachedPlayer()->setDestY(PLAYER_SC02_Y);
    //createRandomEnemies();

    //Intersecção de Mapas, -- TALVEZ fazer classe.. Provavelmente método.
    BITMAP* scenarioClear;
    scenarioClear = load_bitmap("img/scenarioclear.bmp", 0);
    /*while(!key[KEY_ENTER])
    {
        blit(scenarioClear, screen, 0,0,0,0,scenarioClear->w, scenarioClear->h);
        rest(100);
        pAttachedTimer->stateFalse();
    }*/
    pAttachedTimer->stateTrue();

    createRandomTrapsGoons();

    while (!key[KEY_ESC])
    {
        moveEntities();
        charactersAttack();

        collisionCheck();
        move();

        printEntities();
        masked_blit(buffer, screen,0,0,0,0,buffer->w,buffer->h);

        pauseEvent();

       //Se Player estiver pra frente do final do mapa, fecha o loop.
        if (scenarioEnd())
            break;
        rest(REST_TIME);
    }
}

