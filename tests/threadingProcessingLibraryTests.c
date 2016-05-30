#include "../src/threadingProcessingLibrary.h"

void* threadFunc(void *arg)
{
	char *str;
	int i = 0;

	str=(char*)arg;

	while(i < 10 )
	{
		usleep(1);
		threadSaveFunction("threadFunc says:");
		threadSaveFunction(str);
		++i;
	}

	return NULL;
}

threadSaveFunction(const char* msg){
    tpl_
    printf(msg);
}

int main(void)
{
	void* thread1 = tpl_createThread(threadFunc,"thread one is processing...");
	void* thread2 = tpl_createThread(threadFunc,"thread two is processing...");
	void* thread3 = tpl_createThread(threadFunc,"thread three is processing...");
	void* thread4 = tpl_createThread(threadFunc,"thread four is processing...");

	tpl_joinThread(thread1, NULL);
	tpl_joinThread(thread2, NULL);
	tpl_joinThread(thread3, NULL);
	tpl_joinThread(thread4, NULL);

	int i = 0;
	while(i < 10 )
	{
		usleep(1);
		printf("main() is running...\n");
		++i;
	}

    tpl_freeThread(thread1);
    tpl_freeThread(thread2);
    tpl_freeThread(thread3);
    tpl_freeThread(thread4);

	return 0;
}
