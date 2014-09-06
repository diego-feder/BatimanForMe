#include "Scenario01.h"


Scenario01::Scenario01(int startX, int startY):
    BaseScenario(startX, startY)
{
    X = 0;
    mapMove = true;

    //Se não for um novo jogo, carregar as informações do mapa
    if (!newGame())
        loadScenario01();
}

Scenario01::~Scenario01()
{
    saveScenario01();
}


//Salva as informações da fase em um arquivo binário
void Scenario01::saveScenario01()
{
    ofstream myfile ("bin/scenario01.bin", ios::trunc);
    if (myfile.is_open())
    {
        myfile << X << endl;
        myfile.close();
    }
}

//Carrega as informações do cenário guardadas em um arquivo binário
void Scenario01::loadScenario01()
{
    string str;
    ifstream myfile ("bin/scenario01.bin");
    if(myfile.is_open())
    {
        getline(myfile, str);
        X = atoi(str.c_str());
    }
    myfile.close();
}

//Carrega as sprites e cria as máscaras para o cenário
void Scenario01::loadMap()
{
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    if(!buffer)
    {
         allegro_message("Unable to creat Buffer Bitmap.");
    }

    loadSprites("img/map01.bmp", &spriteVector);
    createMasks("img/map01_mask.bmp",1,&maskVector);

}

//Função que cria FAkeJokers randomicamente
void Scenario01::createRandomFakeJokers()
{
    //Alimenta o randomizador
    srand(time(NULL));

    std::mt19937_64 generator(rand());
    std::uniform_int_distribution<unsigned long int> distribution(100,900);

    int i, x, n = 600;
    for(i = 0; i < 7; i++, n += 620)
    {
        x = ((int) distribution(generator)) + n;
        createEntity<FakeJoker, Player*, BaseScenario*, int, int, int, int, int>(pAttachedPlayer, this, 2,1,1,x,PLAYER_START_Y);
    }
}


void Scenario01::move()
{
    mapMove = true;

    //Se o mapa já moveu até o máximo permitido, para de mover
    if (X >= SCENARIO01_RIGHTBORDER)
    {
        mapMove = false;
    }

    //Se o mapa estiver se movendo e o player estiver indo para depois do meio do mapa
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


//Se o player estiver no final do mapa
bool Scenario01::scenarioEnd()
{
    if (pAttachedPlayer->getX() >= SCENARIO01_END_LENGHT || pAttachedPlayer->getHealth() <= 0)
    {
        return true;
    }
    return false;


}

void Scenario01::print(BITMAP* pWhereToPrint)
{
    blit(spriteVector[0], pWhereToPrint, X,0,0,0, spriteVector[0]->w, spriteVector[0]->h);
}

void Scenario01::execute()
{
    loadMap();
    createRandomFakeJokers();

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
        {
            break;
        }
        rest(REST_TIME);
    }
}
