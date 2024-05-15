#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void stack_init_empty(BulletStack *stack) {
    stack->size = 0;
    for (int i = 0; i < MAX_B_STACK_SIZE; i++) {
        stack->bullets_list[i] = EMPTY;
    }
}

void stack_init_rand(BulletStack *stack, int live_bullets, int blanks) {
    assert(live_bullets + blanks <= MAX_B_STACK_SIZE);

    int total_bullets = live_bullets + blanks;
    stack->size = total_bullets;

    int i = 0;
    for (; i < total_bullets; i++) {
        BulletKind bullet;

        if (rand() & 1) {
            if (live_bullets > 0) {
                live_bullets--;
                bullet = LIVE;
            } else {
                break;
            }

        } else {
            if (blanks > 0) {
                blanks--;
                bullet = BLANK;
            } else {
                break;
            }
        }

        stack->bullets_list[i] = bullet;
    }

    for (; live_bullets > 0; live_bullets--) {
        stack->bullets_list[i] = LIVE;
        i++;
    }

    for (; blanks > 0; blanks--) {
        stack->bullets_list[i] = BLANK;
        i++;
    }

    for (; i < MAX_B_STACK_SIZE; i++) {
        stack->bullets_list[i] = EMPTY;
    }
}

BulletKind stack_pop(BulletStack *stack) {
    assert(!stack_is_empty(stack));

    const int index = stack->size;
    const BulletKind bullet = stack->bullets_list[index - 1];

    stack->size--;
    stack->bullets_list[index - 1] = EMPTY;

    return bullet;
}

void stack_push(BulletStack *stack, BulletKind bullet) {
    assert(stack->size != MAX_B_STACK_SIZE);

    stack->size++;
    stack->bullets_list[stack->size] = bullet;
}

bool stack_is_empty(BulletStack *stack) { return stack->size == 0; }

void stack_print(BulletStack *stack) {
    printf("@---@\n");
    printf("Size: %d (Max: %d)\n", stack->size, MAX_B_STACK_SIZE);

    int i = 0;
    for (; i < stack->size; i++) {
        switch (stack->bullets_list[i]) {
        case LIVE:
            printf("%d. live bullet\n", MAX_B_STACK_SIZE - i);
            break;
        case BLANK:
            printf("%d. blank\n", MAX_B_STACK_SIZE - i);
            break;
        case EMPTY:
            printf("empty at %d, this shouldn't be happening!\n", MAX_B_STACK_SIZE);
            break;
        }
    }

    if (stack->size != MAX_B_STACK_SIZE) {
        printf("---\n");
    }

    for (; i < MAX_B_STACK_SIZE; i++) {
        switch (stack->bullets_list[i]) {
        case LIVE:
        case BLANK:
            printf("live or blank bullet at %d, this shouldn't be happening!\n",
                   MAX_B_STACK_SIZE - i);
            break;
        case EMPTY:
            printf("%d. empty spot\n", MAX_B_STACK_SIZE);
            break;
        }
    }
    printf("#---#\n");
}
