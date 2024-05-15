#include "game_state.h"
#include "randgen.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void assert_state_fully_initialized(GameState *state) {
    assert(state->left_player_lives != -1);
    assert(state->right_player_lives != -1);
}

GameState new_game_state() {
    GameState state = {-1, -1, LEFT, {0, {EMPTY}}};
    return state;
}

void reset_game_state(GameState *state, ResetStateOpts options) {
    if (options != PRESERVE_LIVES) {
        state->left_player_lives = MAX_PLAYER_LIVES;
        state->right_player_lives = MAX_PLAYER_LIVES;
    }
    state->turn = (rand() & 1) ? LEFT : RIGHT;

    int size = rand_size();

    int live_bullets = rand_live_bullets(size);
    int blanks = size - live_bullets;

    stack_init_rand(&state->bullets, live_bullets, blanks);
}

void toggle_turn(GameState *state) { state->turn = (state->turn == LEFT) ? RIGHT : LEFT; }
