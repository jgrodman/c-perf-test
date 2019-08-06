#include <stdio.h>

#include "visit.h"

void visit(void (*visitor)()) {
  long int num_reps = 1000L * 1000 * 1000 * 1 ;
  printf("start %lu\n", num_reps);
  for (int i = 0; i < num_reps; i++) {
    visitor();
  }
  printf("end\n");
}
