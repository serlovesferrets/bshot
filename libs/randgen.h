/** Must get called before calling `randint`. Just sets the seed. */
void setup_randgen();

/**
  Generates a random number from `lower_bound` to `upper_bound`.
  Inclusive on both ends.

  Note: you MUST call `setup_randgen()` first.
*/
int randint(int lower_bound, int upper_bound);

int rand_size();

int rand_live_bullets(int size);
