#include "randgen.h"
#include "stack.h"
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

int rand_size() { return randint(2, MAX_B_STACK_SIZE); }

int rand_live_bullets(int size) { return randint(1, size - 1); }
