using namespace std;
#include <iostream>

extern "C" {
#include "../visit.h"
}

void visitor(void){
}


int main() 
{
  long int num_reps = 1000L * 1000 * 1000 * 1 ;

  cout << "start " << num_reps << endl;
  for (int i = 0; i < num_reps; i++) {
    visit(visitor);
  }
  cout << "end" << endl;

  return 0;
}
