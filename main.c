#include "libs/randgen.h"
#include "libs/stack.h"
#include <stdio.h>
#include <stdlib.h>

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

    BulletStack stack;
    stack.bullets = (BulletKind *)malloc(sizeof(BulletKind) * MAX_STACK_SIZE);
    stack_init_rand(&stack, 3, 2);

    stack_print(&stack);

    stack_pop(&stack);
    stack_pop(&stack);

    stack_print(&stack);

    free(stack.bullets);
}
