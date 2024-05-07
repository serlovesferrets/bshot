#include "libs/randgen.h"
#include <stdio.h>

int main(void) {
  setup_randgen();

  int n;

  for (int i = 0; i < 10; i++) {
    n = randint(2, 6);
    printf("%d: %d\n", i, n);
  }
}
