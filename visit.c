#include "visit.h"

void visit(void (*visitor)()) {
  visitor();
}
