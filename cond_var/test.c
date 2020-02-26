#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <sys/time.h>

// Declaration of thread condition variable 
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER; 
  
// declaring mutex 
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 

struct timeval start, end;
  
int done = 1; 
  
// Thread function 
void* foo() 
{ 
  
    // acquire a lock 
    pthread_mutex_lock(&lock);  // in our case, each reactor would hold its lock indefinitely
    pthread_cond_wait(&cond1, &lock); 
  
    gettimeofday(&end, NULL);

  long seconds = end.tv_sec - start.tv_sec;
  long micros = ((seconds * 1000000) + end.tv_usec) - start.tv_usec;
  printf("%ld\n", micros);

  
  
    return NULL; 
} 
  
// Driver code 
int main() 
{ 
    pthread_t tid1; 
  
    pthread_create(&tid1, NULL, foo, NULL); 
  
    sleep(1); 
  
gettimeofday(&start, NULL);
        pthread_cond_signal(&cond1); 
  
    pthread_join(tid1, NULL); 
  
    return 0; 
} 
