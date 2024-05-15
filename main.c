#include "libs/game_state.h"
#include "libs/lives.h"
#include "libs/randgen.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define loop while (1)

int main(void) {
    setup_randgen();

    GameState state = new_game_state();
    reset_game_state(&state, NO_OPTS);

    BulletKind bullet;

    loop {
        if (is_game_over(state.left_player_lives)) {
            printf("Right player wins!\n");
            break;
        }

        if (is_game_over(state.right_player_lives)) {
            printf("Left player wins!\n");
            break;
        }

        if (stack_is_empty(&state.bullets)) {
            printf("Reloading...\n");
            reset_game_state(&state, PRESERVE_LIVES);
        }

        bullet = stack_pop(&state.bullets);

        if (state.turn == LEFT) {
            printf("LEFT is Shooting!\n");

            switch (bullet) {
            case LIVE:
                printf("Live bullet!\n");
                deal_damage(&state.right_player_lives);
                break;

            case BLANK:
                printf("But it was a blank...\n");
                break;

            case EMPTY:
                printf("fuck >_>\n");
                exit(1);
            }
        } else {
            printf("RIGHT is Shooting!\n");

            switch (bullet) {
            case LIVE:
                printf("Live bullet!\n");
                deal_damage(&state.left_player_lives);
                break;

            case BLANK:
                printf("But it was a blank...\n");
                break;

            case EMPTY:
                printf("fuck >_>\n");
                exit(1);
            }
        }

        printf("Summary: LEFT: %d, RIGHT: %d\n", state.left_player_lives,
               state.right_player_lives);

        toggle_turn(&state);
    }
}
