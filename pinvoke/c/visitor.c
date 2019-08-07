#include <stdio.h>
#include <time.h>

#include "../visit.h"

clock_t start, end;
double cpu_time_used;


int main()
{
  long int num_reps = 1000L * 1000 * 1000 * 1 ;
  printf("start %lu\n", num_reps);
  start = clock();
  for (long i = 0; i < num_reps; i++) {
    visit();
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("end: %f\n", cpu_time_used);


  return 0;
}
