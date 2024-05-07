#include "libs/randgen.h"
#include <stdio.h>

void test_random_generation() {
  int total_bullets, live_bullets, blanks;

  const char *output = "%d. %d lives, %d blanks, total: %d\n";
  for (int i = 0; i < 10; i++) {
    total_bullets = randint(2, 6);
    live_bullets = randint(1, total_bullets - 1);
    blanks = total_bullets - live_bullets;

    printf(output, i, live_bullets, blanks, total_bullets);
  }
}

int main(void) {
  setup_randgen();
  test_random_generation();
}
