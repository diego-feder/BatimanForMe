#include "Thread.h"


Thread::Thread()
{
    m_hThread = NULL;
    m_ThreadID = 0;
    //execute();
}

Thread::~Thread() {}

void Thread::startThread()
{
    m_hThread = (HANDLE)_beginthreadex(
                                       NULL,
                                       0,(PBEGINTHREADEX_THREADFUNC)Thread::threadFunction,
                                       (LPVOID)this,
                                       0,
                                       (PBEGINTHREADEX_THREADID)&m_ThreadID);

    if(m_hThread)
        cout << "Thread launched" << endl;
}

void Thread::waitForExit()
{
    WaitForSingleObject(m_hThread, INFINITE);
    CloseHandle(m_hThread);
}

DWORD WINAPI Thread::threadFunction(LPVOID param)
{
    Thread* pTO = (Thread*)param;

    return pTO->threadMemberFunction();
}


DWORD Thread::threadMemberFunction()
{

}
