#pragma once

#include "stdafx.h"



class Ranking {
private:
    typedef struct ScoreCell
    {
        string name;
        int score;
    };

	vector <ScoreCell*> scores;

public:

	Ranking();
	~Ranking();
    void readFile();
    void includeScore(int score, string name);
    void reverseSortFile();
    void writeFile();
};

