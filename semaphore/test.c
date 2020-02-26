#include <stdio.h>
#include <pthread.h>
#include <semaphore.h> 
#include <unistd.h> 
#include <sys/time.h>


struct timeval start, end;

sem_t mutex;
void* thread(void* arg) 
{ 
    sem_wait(&mutex); 
		gettimeofday(&end, NULL);
  
	long seconds = end.tv_sec - start.tv_sec;
	long micros = ((seconds * 1000000) + end.tv_usec) - start.tv_usec;
	printf("%ld\n", micros);
} 
  
  
int main() 
{ 
    sem_init(&mutex, 0, 0); 
    pthread_t t1; 
    pthread_create(&t1,NULL,thread,NULL); 
    sleep(2); 
		gettimeofday(&start, NULL);
    sem_post(&mutex); 

    pthread_join(t1,NULL); 
    sem_destroy(&mutex); 
    return 0; 
} 
