#pragma once

#include "stdafx.h"

#include"Play.h"
#include"AllegroManager.h"
#include"Scenario01.h"
#include"Ranking.h"


class Game {
private:
	AllegroManager objAllegroManager;

public:
	Game();
	~Game();
	void execute();
};
