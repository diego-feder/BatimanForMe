#pragma once


#include "stdafx.h"
#include "Thread.h"

class Timer : public Thread
{
private:
    time_t ti, tf;
    int t1, t2, t3;
    double deltaT;
    bool timerState;
    DWORD threadMemberFunction();

public:
    Timer();
    ~Timer();


    double getDeltaT();
    void printTimer(BITMAP* pWhereToPrint);
    void saveT1();
    void saveT2();
    void saveT3();
    void stateTrue();
    void stateFalse();
};
