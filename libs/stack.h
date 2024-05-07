#include "bullet_kind.h"
#include <stdbool.h>

#define MAX_STACK_SIZE 6

// A stack of bullets.
typedef struct {
  // The actual size of the stack, also the element that's going to get popped.
  int size;
  /** The highest size the stack can have, since this data structure is supposed
   * to be reusable in the same program. */
  int max_size;
  // The bullets inside the stack.
  BulletKind *bullets;
} BulletStack;

// Initialize a stack with only `EMPTY` bullets, of `size` 0.
void stack_init_empty(BulletStack *stack);
// Initialize a stack with a certain number of `live_bullets` and `blanks`.
void stack_init_rand(BulletStack *stack, int live_bullets, int blanks);

// Returns the last bullet of the stack.
BulletKind stack_pop(BulletStack *stack);

// Pushes the `bullet` at the end of the stack.
void stack_push(BulletStack *stack, BulletKind bullet);

// Checks if the stack is of `size` is 0 (`0`) or not (`1`).
bool stack_is_empty(BulletStack *stack);

// Prints data about the stack.
void stack_print(BulletStack *stack);
