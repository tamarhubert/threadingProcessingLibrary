/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#include "threadingProcessingLibrary.h"

#ifdef _WIN32
#include <process.h>

#elif __linux__

#include <pthread.h>
#include <stdlib.h>

void* tpl_createThread(void* (*function) (void *), void* arg){
    pthread_t* thread = malloc(sizeof(pthread_t));
	pthread_create(thread,NULL,function, arg);
	return thread;
}
int tpl_cancelThread(void* thread){
    return pthread_cancel(*(pthread_t*)thread);
}
int tpl_joinThread(void* thread, void** result){
    return pthread_join(*(pthread_t*)thread, result);
}
int tpl_freeThread(void* thread){
    free(thread);
}

void* tpl_createMutex(){
    pthread_mutex_t* mutex = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(mutex, NULL);
    return mutex;
}
int tpl_lockMutex(void* mutex){
    return pthread_mutex_lock(mutex);
}
int tpl_unlockMutex(void* mutex){
    return pthread_mutex_unlock(mutex);
}
int tpl_freeMutex(void* mutex){
    pthread_mutex_destroy(mutex);
}

#else
#   error "Unknown compiler"
#endif

