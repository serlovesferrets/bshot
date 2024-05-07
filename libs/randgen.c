#include "randgen.h"
#include <stdlib.h>
#include <sys/time.h>

void setup_randgen() {
  struct timeval time;
  gettimeofday(&time, NULL);
  srand(time.tv_usec);
}

int randint(int lower_bound, int upper_bound) {
  return rand() % (upper_bound - lower_bound + 1) + lower_bound;
}
