using namespace std;
#include <iostream>

extern "C" {
#include "../visit.h"
}

void visitor(void){
}


int main() 
{
  visit(visitor);

  return 0;
}
