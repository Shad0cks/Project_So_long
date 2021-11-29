#include "../include/header.h"

void init_player_struct(player_t *player)
{
    player->count_move = 0;
    player->pos_x = 0;
    player->pos_y = 0;
    player->skin_height = 64;
    player->skin_width = 64;
    player->sprite = NULL;
	player->want_exit = 0;
    player->will_die = 0;
}