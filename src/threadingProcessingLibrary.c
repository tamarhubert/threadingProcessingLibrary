/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#include "threadingProcessingLibrary.h"

#ifdef _WIN32
#include <process.h>

tpl_Thread* tpl_createThread(void* (*function) (void *), void* arg){
    return CreateThread(NULL, 0, function, arg, 0, NULL);
}
int tpl_cancelThread(tpl_Thread* thread){
    return TerminateThread(thread, 0);
}
int tpl_joinThread(tpl_Thread* thread, void** result){
    return WaitForSingleObject(thread, INFINITE);
}
int tpl_freeThread(tpl_Thread* thread){
    return CloseHandle(thread);
}

tpl_Mutex* tpl_createMutex(){
    return CreateMutex( NULL, FALSE, NULL);
}
int tpl_lockMutex(tpl_Mutex* mutex){
    return WaitForSingleObject(mutex, INFINITE);
}
int tpl_unlockMutex(tpl_Mutex* mutex){
    return ReleaseMutex(mutex);
}
int tpl_freeMutex(tpl_Mutex* mutex){
    return CloseHandle(mutex);
}

#elif __linux__

#include <pthread.h>
#include <stdlib.h>

tpl_Thread* tpl_createThread(void* (*function) (void *), void* arg){
    pthread_t* thread = malloc(sizeof(pthread_t));
    pthread_create(thread,NULL,function, arg);
    return  thread;
}
int tpl_cancelThread(tpl_Thread* thread){
    return pthread_cancel(*(pthread_t*)thread);
}
int tpl_joinThread(tpl_Thread* thread, void** result){
    return pthread_join(*(pthread_t*)thread, result);
}
int tpl_freeThread(tpl_Thread* thread){
    free(thread);
}

tpl_Mutex* tpl_createMutex(){
    pthread_mutex_t* mutex = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(mutex, NULL);
    return mutex;
}
int tpl_lockMutex(tpl_Mutex* mutex){
    return pthread_mutex_lock(mutex);
}
int tpl_unlockMutex(tpl_Mutex* mutex){
    return pthread_mutex_unlock(mutex);
}
int tpl_freeMutex(tpl_Mutex* mutex){
    pthread_mutex_destroy(mutex);
    free(mutex);
}

#else
#   error "Unknown compiler"
#endif

