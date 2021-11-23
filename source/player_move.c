#include "../include/header.h"

int go_up(mlx_t *mlx_st)
{
    ft_printf("destroying\n");
    mlx_destroy_image(mlx_st->mlx, mlx_st->player->player_sprite);
    put_sprite(mlx_st, 'P', "/Users/pierre-louis/Documents/C/Project_So_long/sprite/item.xpm");
    //put_image
    return (0);
}