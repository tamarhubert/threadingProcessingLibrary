#ifndef TPL_THREADING_PROCESSING_LIBRARY_H
#define TPL_THREADING_PROCESSING_LIBRARY_H
#include <stdio.h>

void* tpl_createThread(void* (*) (void *), void*);
int tpl_cancelThread(void*);
int tpl_joinThread(void*, void**);
int tpl_freeThread(void*);

void* tpl_createMutex();
int tpl_lockMutex(void*);
int tpl_unlockMutex(void*);
int tpl_freeMutex(void*);


#endif /* TPL_THREADING_PROCESSING_LIBRARY_H */
