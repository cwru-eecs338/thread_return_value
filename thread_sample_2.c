#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *print_message_function(void * ptr){
	char * message;
	message=(char *)ptr;
	printf("%s\t",message);
	printf("PID:%u\n",(unsigned int)pthread_self());
	pthread_exit("thread all done");
}

void main(){
	pthread_t thread1,thread2;
	char *message1="Thread 1";
	char *message2="Thread 2";
	int iret1,iret2;
	void *pth_join_ret1;
	void *pth_join_ret2;
	iret1=pthread_create(&thread1, NULL, print_message_function, (void *)"Thread 1 here");
	iret2=pthread_create(&thread2, NULL, print_message_function, (void *)message2);
	pthread_join(thread1, &pth_join_ret1);
	pthread_join(thread2, &pth_join_ret2);
	
	printf("Thread 1 returns: %d\n",iret1);
	printf("Thread 2 returns: %d\n",iret2);
	printf("pthread_join 1 returns: %s\n",(char *)pth_join_ret1);
	printf("pthread_join 2 returns: %s\n",(char *)pth_join_ret2);
}
