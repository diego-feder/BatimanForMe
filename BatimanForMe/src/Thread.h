#pragma once

#include "stdafx.h"
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>


typedef unsigned (WINAPI *PBEGINTHREADEX_THREADFUNC)(
LPVOID lpThreadParameter
);
typedef unsigned *PBEGINTHREADEX_THREADID;

class Thread
{
protected:
    virtual DWORD threadMemberFunction();
    HANDLE m_hThread;
    DWORD m_ThreadID;

public:
    Thread();
    ~Thread();
    void startThread();
    void waitForExit();
    static DWORD WINAPI threadFunction (LPVOID param);
};
