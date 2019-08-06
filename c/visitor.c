#include <stdio.h>

#include "../visit.h"

void visitor(void){
}

int main()
{
  long int num_reps = 1000L * 1000 * 1000 * 1 ;
  printf("start %lu\n", num_reps);
  for (int i = 0; i < num_reps; i++) {
    visit(visitor);
  }
  printf("end\n");
  return 0;
}
