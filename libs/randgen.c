#include "randgen.h"
#include <stdlib.h>
#include <time.h>

void setup_randgen() { srand(time(NULL)); }

int randint(int lower_bound, int upper_bound) {
  int num = rand() % (upper_bound - lower_bound + 1) + lower_bound;
  return num;
}
