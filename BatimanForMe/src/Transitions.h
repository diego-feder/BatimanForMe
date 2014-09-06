#pragma once

#include "stdafx.h"

class Transitions
{
private:
    int index;
    BITMAP* transition[3];

public:
    Transitions();
    ~Transitions();

    void loadBG();
    void print(BITMAP* pWhereToPrint);
    void execute();
    void screenWait();
};
