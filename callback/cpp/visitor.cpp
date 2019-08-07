using namespace std;
#include <iostream>

extern "C" {
#include "../visit.h"
}

 /*__attribute__((stdcall))*/ void visitor(void){
}


int main() 
{
  visit(visitor);

  return 0;
}
