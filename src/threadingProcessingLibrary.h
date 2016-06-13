/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#ifndef TPL_THREADING_PROCESSING_LIBRARY_H
#define TPL_THREADING_PROCESSING_LIBRARY_H
#include <stdio.h>

#ifdef _WIN32

#include <windows.h>
#include <process.h>

typedef HANDLE tpl_Thread;
typedef HANDLE tpl_Mutex;

#elif __linux__

#include "pthread.h"
typedef pthread_t tpl_Thread;
typedef pthread_mutex_t tpl_Mutex;

#else

#error "unknown compiler"

#endif

tpl_Thread* tpl_createThread(void* (*) (void *), void*);
int tpl_cancelThread(tpl_Thread*);
int tpl_joinThread(tpl_Thread*, void**);
int tpl_freeThread(tpl_Thread*);

tpl_Mutex*  tpl_createMutex();
int tpl_lockMutex(tpl_Mutex*);
int tpl_unlockMutex(tpl_Mutex*);
int tpl_freeMutex(tpl_Mutex*);

#endif /* TPL_THREADING_PROCESSING_LIBRARY_H */
