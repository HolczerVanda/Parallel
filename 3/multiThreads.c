#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *newThread(void *vargp)
{
    printf("I'm another thread\n");
    printf("Wait 4 sec\n");
	sleep(4);
	return NULL;
}

int main()
{
	pthread_t thread_id;
	printf("Wait 8 sec\n");
    sleep(8);
	pthread_create(&thread_id, NULL, newThread, NULL);
	pthread_join(thread_id, NULL);
	printf("I'm the main again\n");
	exit(0);
}
