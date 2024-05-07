#include "bullet_kind.h"

typedef struct {
  int size;
  int max_size;
  BulletKind *bullets;
} BulletStack;

void stack_init_empty(BulletStack *stack);

void stack_init_rand(BulletStack *stack, int live_bullets, int blanks);

void stack_print(BulletStack *stack);
