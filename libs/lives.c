#include "lives.h"
#include <assert.h>
#include <stdbool.h>

void deal_damage(Lives *lives) {
    const int current_lives = *lives;
    assert(current_lives > -1 && current_lives < MAX_PLAYER_LIVES + 1);

    *lives = current_lives - 1;
}

bool is_game_over(const Lives lives) { return lives == 0; }
