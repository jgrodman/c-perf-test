#include <stdio.h>

#include "../visit.h"

void /*__attribute__((cdecl))*/ visitor(void);

void visitor(void){
}

int main()
{
  visit(visitor);
  return 0;
}
