#include "../include/header.h"

void exit_func(void* params)
{
    mlx_t *mlx_st;
    mlx_st = (mlx_t *)params;
    mlx_destroy_window(mlx_st->mlx, mlx_st->window);
	free(mlx_st->map_b);
    exit(0);
}
int exit_cross(int keycode, void* params)
{
    (void)keycode;
    (void)params;
    exit(0);
    return (0); 
}
int key_listen(int keycode, void* params)
{
    //ft_printf("keycode : %d\n", keycode);
    if (keycode == 53)
        exit_func(params);
    if (keycode == 13)
        go_up(params);
	if (keycode == 1)
		go_down(params);
	if (keycode == 0)
		go_left(params);
	if (keycode == 2)
		go_right(params);
    return (0);
}

void refresh_map(mlx_t *mlx_st)
{
	put_sprite(mlx_st, '0', "../sprite/sand.xpm", mlx_st->map_b);
    put_sprite(mlx_st, '1', "../sprite/wall.xpm", mlx_st->map_b);
    put_sprite(mlx_st, 'C', "../sprite/item.xpm", mlx_st->map_b);
    put_sprite(mlx_st, 'E', "../sprite/door.xpm", mlx_st->map_b);
    put_sprite(mlx_st, 'P', "../sprite/player.xpm", mlx_st->map_b);
	if (mlx_st->player->count_move > 1)
		mlx_string_put(mlx_st->mlx, mlx_st->window, 20, 20, 0x52e710, ft_strjoin("MOVES COUNT : ", ft_itoa(mlx_st->player->count_move)));
	else
		mlx_string_put(mlx_st->mlx, mlx_st->window, 20, 20, 0x52e710, ft_strjoin("MOVE COUNT : ", ft_itoa(mlx_st->player->count_move)));
}

int main(void)
{
    map_t map;
    player_t player;
	char **buffer;
	buffer = NULL;
    init_player_struct(&player);
    map.max_x = -1;
    map.max_y = -1;
    if(!check_all_piece())
    {
        ft_printf("no valid piece in map");
        exit(-1);
    }
    if (!check_piece_here('P') || !check_piece_here('E') || !check_piece_here('C'))
    {
        ft_printf("map piece error");
        exit(-1);
    }
    if(valid_map() <= 2 || calc_map_size(&map) == -1 || check_close(&map) == -1)
    {
        ft_printf("map error");
        exit(-1);
    }
    mlx_t mlx_st;
    mlx_st.player = &player;
    mlx_st.mlx = mlx_init();
    if (mlx_st.mlx == NULL)
        exit(-1);
    mlx_st.window = mlx_new_window(mlx_st.mlx, map.max_x * 40, map.max_y * 40, "So_long");
	buffer = put_buffer();
	mlx_st.map_b = buffer;
	refresh_map(&mlx_st);
	mlx_hook(mlx_st.window, 2, (1L<<13), key_listen, &mlx_st);
    mlx_hook(mlx_st.window, 17, (1L<<19), exit_cross, NULL);
    mlx_loop(mlx_st.mlx); 
}