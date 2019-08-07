#include <stdio.h>
#include <locale.h>

#include "visit.h"

void visit(void (*visitor)()) {
  long int num_reps = 1000L * 1000 * 1000 * 1 ;
  setlocale(LC_NUMERIC, "");
  printf("start %'lu\n", num_reps);
  for (long i = 0; i < num_reps; i++) {
    visitor();
  }
  printf("end\n");
}
