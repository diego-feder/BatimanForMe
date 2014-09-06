#include "Timer.h"

Timer::Timer() :
Thread()
{
    timerState = true;
    time(&ti);
    t1 = t2 = t3 = 0;


}

Timer::~Timer()
{

}

double Timer::getDeltaT()
{
    return deltaT;
}

DWORD Timer::threadMemberFunction()
{
    while(true)
    {
        if(timerState == false)
        {
            time(&ti);
        }

        time(&tf);
        deltaT = difftime(tf, ti);
        Sleep(100);
    }
}

void Timer::printTimer(BITMAP* pWhereToPrint)
{
    textprintf_ex(pWhereToPrint, font, 260, 20, makecol(255,255,255), -1, "TIME: %d", (int)deltaT + t1 + t2 + t3);
}

void Timer::saveT1()
{
    t1 = (int)deltaT;
    time(&ti);
}

void Timer::saveT2()
{
    t2 = (int)deltaT;
    time(&ti);
}

void Timer::saveT3()
{
    t3 = (int)deltaT;
    time(&ti);
}

void Timer::stateTrue()
{
    timerState = true;
}

void Timer::stateFalse()
{
    timerState = false;
}
