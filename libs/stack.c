#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 6;

void stack_init_empty(BulletStack *stack) {
  stack->max_size = MAX_SIZE;

  stack->size = 0;
  for (int i = 0; i < stack->max_size; i++) {
    stack->bullets[i] = EMPTY;
  }
}

void stack_init_rand(BulletStack *stack, int live_bullets, int blanks) {
  stack->max_size = MAX_SIZE;

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

    stack->bullets[i] = bullet;
  }

  for (; live_bullets > 0; live_bullets--) {
    stack->bullets[i] = LIVE;
    i++;
  }

  for (; blanks > 0; blanks--) {
    stack->bullets[i] = BLANK;
    i++;
  }

  for (; i < stack->max_size; i++) {
    stack->bullets[i] = EMPTY;
  }
}

BulletKind stack_pop(BulletStack *stack) {
  const int index = stack->size;
  const BulletKind bullet = stack->bullets[index];

  stack->size--;
  stack->bullets[index] = EMPTY;

  return bullet;
}

void stack_push(BulletStack *stack, BulletKind bullet) {
  stack->size++;
  stack->bullets[stack->size] = bullet;
}

bool stack_is_empty(BulletStack *stack) { return stack->size == 0; }

void stack_print(BulletStack *stack) {
  printf("Size: %d (Max: %d)\n", stack->size, stack->max_size);

  int i = 0;
  for (; i < stack->size; i++) {
    switch (stack->bullets[i]) {
    case LIVE:
      printf("%d. live bullet\n", i + 1);
      break;
    case BLANK:
      printf("%d. blank\n", i + 1);
      break;
    case EMPTY:
      printf("empty at %d, this shouldn't be happening!\n", i + 1);
      break;
    }
  }

  if (stack->size != stack->max_size) {
    printf("---\n");
  }

  for (; i < stack->max_size; i++) {
    switch (stack->bullets[i]) {
    case LIVE:
    case BLANK:
      printf("live or blank bullet at %d, this shouldn't be happening!\n",
             i + 1);
      break;
    case EMPTY:
      printf("%d. empty spot\n", i + 1);
      break;
    }
  }
}
