/*
* The linked list library
*
* Created by: Tamar Hubert
*/

#include <stdio.h>

#include "../src/threadingProcessingLibrary.h"

void* threadFunc(void *arg)
{
	char *str;
	int i = 0;

	str=(char*)arg;

	while(i < 10 )
	{
		usleep(1);
		printf("threadFunc says: %s\n", str);
		++i;
	}

	return NULL;
}

int main(void)
{
    tpl_Thread* thread1 = tpl_createThread(threadFunc,"thread one is processing...");
    tpl_Thread* thread2 = tpl_createThread(threadFunc,"thread two is processing...");
    tpl_Thread* thread3 = tpl_createThread(threadFunc,"thread three is processing...");
    tpl_Thread* thread4 = tpl_createThread(threadFunc,"thread four is processing...");

    int i = 0;
    while(i < 10 )
    {
        usleep(1);
        printf("main() is running...\n");
        ++i;
    }

    tpl_joinThread(thread1, NULL);
    tpl_joinThread(thread2, NULL);
    tpl_joinThread(thread3, NULL);
    tpl_joinThread(thread4, NULL);

    tpl_freeThread(thread1);
    tpl_freeThread(thread2);
    tpl_freeThread(thread3);
    tpl_freeThread(thread4);

    return 0;
}
