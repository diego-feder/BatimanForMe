#include "Play.h"

Play::Play():
objPlayer(PLAYER_START_SCORE,PLAYER_START_HEALTH,PLAYER_START_ATTACK,0,PLAYER_START_X,PLAYER_START_Y - 50, 0, 0),
objScenario01(100,294),
objScenario02(100,212)
{
    objTimer.startThread();
    objPlayer.attachRanking(&objRanking);

    scenarioNumber = 1;

    if (!newGame())
    {
        loadPlay();
    }
}

Play::~Play()
{
    savePlay();
}

bool Play::newGame()
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

void Play::savePlay()
{
    ofstream myfile ("bin/play.bin", ios::trunc);
    if (myfile.is_open())
    {
        myfile << scenarioNumber << endl;
        myfile.close();
    }
}

void Play::loadPlay()
{
    string str;
    ifstream myfile ("bin/play.bin");
    if(myfile.is_open())
    {
        getline(myfile, str);
        scenarioNumber = atoi(str.c_str());
    }
    myfile.close();
}

void Play::reLoadGame()
{
    ofstream filePlay ("files/play.txt", ios::trunc);
    if(filePlay.is_open())
    {
        allegro_message("Game is lost, New Game Created");
        filePlay << "New" << endl;
        exit(0);
    }
}

void Play::scenario01_init()
{
    objSoundManager.loadTheme("sounds/scenario01Theme.wav");
    objSoundManager.playTheme();
    objScenario01.attachPlayer(&objPlayer);
    objScenario01.attachTimer(&objTimer);
    objPlayer.attachScenario(static_cast<BaseScenario*>(&objScenario01));
    objCollisionManager.attachScenario(static_cast<BaseScenario*>(&objScenario01));
}

void Play::scenario02_init()
{
    objSoundManager.loadTheme("sounds/scenario02Theme.wav");
    objSoundManager.playTheme();
    objScenario02.attachPlayer(&objPlayer);
    objScenario02.attachTimer(&objTimer);
    objPlayer.attachScenario(static_cast<BaseScenario*>(&objScenario02));
    objCollisionManager.attachScenario(static_cast<BaseScenario*>(&objScenario02));

}

void Play::scenario03_init()
{
    objSoundManager.loadTheme("sounds/scenario03Theme.wav");
    objSoundManager.playTheme();
    objScenario03.attachPlayer(&objPlayer);
    objScenario03.attachTimer(&objTimer);
    objScenario03.createBoss();
    objPlayer.attachScenario(static_cast<BaseScenario*>(&objScenario03));
    objScenario03.getBoss()->attachPlayer(&objPlayer);
    objScenario03.getBoss()->attachTimer(&objTimer);
    objScenario03.getBoss()->attachScenario(static_cast<BaseScenario*>(&objScenario03));
    objCollisionManager.attachScenario(static_cast<BaseScenario*>(&objScenario03));

}

void Play::execute()
{
    objSoundManager.loadTheme("sounds/instructionsTheme.wav");
    objSoundManager.playTheme();

    objTimer.stateFalse();
    objTransitions.execute();
    objTimer.stateTrue();

    objSoundManager.stopTheme();

    if (objPlayer.getHealth() <= 0)
    {
        reLoadGame();
    }


    scenario01_init();
    objScenario01.execute();
    objTimer.saveT1();



    if(objScenario01.scenarioEnd() && (objPlayer.getHealth() > 0))
    {

        objTimer.stateFalse();
        objTransitions.execute();
        objTimer.stateTrue();
        objSoundManager.stopTheme();
        scenario02_init();
        objScenario02.execute();
        objTimer.saveT2();
        objSoundManager.stopTheme();

        if (objScenario02.scenarioEnd() &&(objPlayer.getHealth() > 0))
        {

            objTransitions.execute();
            objTimer.stateTrue();
            scenario03_init();
            objScenario03.execute();
            objTimer.saveT3();
        }
    }
}
