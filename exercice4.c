#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define N 2

sem_t semaphore;

void *fonction1(void *arg){
	printf("fonction1 : debut\n");
	for(int i=0;i<100;i++)
		printf("%d ",i);
	printf("\nfonction 1 : fin \n");
	sem_post(&semaphore);
	pthread_exit(NULL);
}

void *fonction2(void *arg){
	sem_wait(&semaphore);
	printf("fonction2 : debut\n");
	for(int i=100;i>0;i--)
		printf("%d ",i);
	printf("\nfonction2 : fin\n");
	pthread_exit(NULL);
}

int main(int argc,char *argv[]){
	pthread_t tid[N];
	void *(*func[])(void*)={fonction1,fonction2};
	int err;
	err=sem_init(&semaphore,0,0);
	if(err!=0)
		printf("\nErreur sem_init:[%d]",err);
	for(int i=0;i<N;i++){
		err=pthread_create(&(tid[i]),NULL,func[i],NULL);
		if(err!=0){
			printf("\nErreur de création du thread :[%d]",err);
		}
	}
	for(int i=0;i<N;i++){
		err=pthead_join(tid[i],NULL);
		if(err!=0){
			printf("\nErreur pthread_join :[%d]",err);
		}
	}
	err=sem_destroy(&semaphore);
	if(err!=0){
		printf("\nErreur sem_destroy :");
	}
	return(EXIT_SUCCESS);
}