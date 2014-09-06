#include "Ranking.h"


Ranking::Ranking()
{

}

Ranking::~Ranking() {

}


/*void Ranking::printFile()
{
    for(int i = 0; (unsigned int)i< scores.size(); i++)
    {
        cout <<  scores[i] << endl;
    }

}*/

void Ranking::includeScore(int score, string name)
{
    ScoreCell* pAux = new ScoreCell;
    pAux->name = name;
    pAux->score = score;
    scores.push_back(pAux);
}

void Ranking::readFile()
{
    int i;
    string stringAux;
    ifstream myfile ("files/highscores.txt");
    if (myfile.is_open())
    {
        /*cout << "------------------" << endl
             << "     READING      " << endl
             << "------------------" << endl << endl;*/

        for(i = 0; !myfile.eof(); i++)
        {
            ScoreCell* pAux = new ScoreCell;
            getline(myfile,pAux->name);

            if (pAux->name == "" || pAux->name == "/n")
            {
                break;
            }

            getline(myfile,stringAux);
            pAux->score = atoi(stringAux.c_str());
            scores.push_back(pAux);
        }
        //printFile();
        myfile.close();
    }
    else
    {
        ofstream file("files/highscores.txt");
        if(!file.is_open())
        {
            allegro_message("Unable to read and create file");
        }
        else
        {
            file.close();
        }
    }
}

void Ranking::writeFile()
{

  ofstream myfile ("files/highscores.txt");
  if (myfile.is_open())
  {
    /*cout << "------------------" << endl
         << "     WRITING      " << endl
         << "------------------" << endl << endl;*/
    myfile.flush();
    for(int i=0; (unsigned int)i < scores.size(); i++)
    {
        myfile << scores[i]->name;
        myfile << endl;
        myfile << scores[i]->score;
        myfile << endl;
    }
    //printFile();
    myfile.close();
  }
  else allegro_message("Unable to write file");
}

void Ranking::reverseSortFile()
{
        unsigned int index;
        bool run;
        ScoreCell* pAux = new ScoreCell;

        do
        {
            run = false;
            for(index = 0; index < scores.size()-1; index++)
            {
               if(scores[index]->score < scores[index+1]->score)
               {
                   pAux = scores[index];
                   scores[index] = scores[index+1];
                   scores[index+1] = pAux;
                   run = true;
               }
            }
        }while(run);
}


