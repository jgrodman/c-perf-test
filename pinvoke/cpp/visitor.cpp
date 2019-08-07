using namespace std;
#include <iostream>
#include <time.h>

extern "C" {
#include "../visit.h"
}



int main()
{

  clock_t start, end;
  double cpu_time_used;
  long int num_reps = 1000L * 1000 * 1000 * 1 ;
  cout << "start " << num_reps << endl;
  start = clock();
  for (long i = 0; i < num_reps; i++) {
    visit();
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  cout << "end: " << cpu_time_used << endl;

  return 0;
}
