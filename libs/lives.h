#include <stdbool.h>

#define MAX_PLAYER_LIVES 3

// A simple int, that represents the number of lives.
typedef int Lives;

// Rimuove un punto dalla vita passata.
void deal_damage(Lives *lives);

bool is_game_over(const Lives lives);
