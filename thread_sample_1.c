#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * function1(void *);

void main(){
	pthread_t thread_id;

	int status=7, *p_status;
	printf("the previous status is %d\n",status);
	pthread_create(&thread_id, NULL, function1,(void *)&status);
	printf("new thread created\n");

	fflush(stdout);
	pthread_join(thread_id, (void **)&p_status);
	printf("the updated status is %d \n",*p_status);
}

void * function1(void * para1){

	int *p;
	p=(int *)para1;
	*p=12;

	pthread_exit((void *)p);
//	return((void *)p); 
}


