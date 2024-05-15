#include "lives.h"
#include "stack.h"
#include <stdbool.h>
#include <stdio.h>

typedef enum { RIGHT, LEFT } Turn;

typedef struct {
    Lives left_player_lives;
    Lives right_player_lives;
    Turn turn;
    BulletStack bullets;
} GameState;

GameState new_game_state();

void assert_state_fully_initialized(GameState *state);

typedef enum { PRESERVE_LIVES, NO_OPTS } ResetStateOpts;

void reset_game_state(GameState *state, ResetStateOpts options);

void toggle_turn(GameState *state);
