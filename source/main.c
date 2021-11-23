#include "../include/header.h"

void free_map(char **buffer)
{
	int i;

	i = 0;
	while(buffer[i] != NULL)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer[i]);
}

void exit_func(void* params)
{
    mlx_t *mlx_st;
    mlx_st = (mlx_t *)params;
    mlx_destroy_window(mlx_st->mlx, mlx_st->window);
	free_map(mlx_st->map_b);
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
	char *number;
	char *string;

	put_sprite(mlx_st, '0', "../sprite/sand.xpm", mlx_st->map_b);
    put_sprite(mlx_st, '1', "../sprite/wall.xpm", mlx_st->map_b);
    put_sprite(mlx_st, 'C', "../sprite/item.xpm", mlx_st->map_b);
    put_sprite(mlx_st, 'E', "../sprite/door.xpm", mlx_st->map_b);
    put_sprite(mlx_st, 'P', "../sprite/player.xpm", mlx_st->map_b);
	number = ft_itoa(mlx_st->player->count_move);
	string = ft_strjoin("MOVES COUNT : ", number);
	if (mlx_st->player->count_move > 1)
	{
		mlx_string_put(mlx_st->mlx, mlx_st->window, 20, 20, 0x52e710, string);
		free(number);
		free(string);
	}
	else
	{
		mlx_string_put(mlx_st->mlx, mlx_st->window, 20, 20, 0x52e710, string);
		free(number);
		free(string);
	}
}

int main(void)
{
    map_t map;
    player_t player;
	char **buffer;
	buffer = put_buffer();
    init_player_struct(&player);
    map.max_x = -1;
    map.max_y = -1;

	if(!check_all_piece(buffer))
    {
        ft_printf("no valid piece in map");
        free_map(buffer);
		exit(-1);
    }
    if (!check_piece_here(buffer, 'P') || !check_piece_here(buffer, 'E') || !check_piece_here(buffer, 'C'))
    {
        ft_printf("map piece error");
		free_map(buffer);
        exit(-1);
    }
	if(valid_map(buffer) <= 2 || calc_map_size(buffer, &map) == -1 || check_close(buffer, &map) == -1)
    {
        ft_printf("map error");
		free_map(buffer);
        exit(-1);
    }
    mlx_t mlx_st;
    mlx_st.player = &player;
    mlx_st.mlx = mlx_init();
    if (mlx_st.mlx == NULL)
        exit(-1);
    mlx_st.window = mlx_new_window(mlx_st.mlx, map.max_x * 40, map.max_y * 40, "So_long");
	mlx_st.map_b = buffer;
	refresh_map(&mlx_st);
	mlx_hook(mlx_st.window, 2, (1L<<13), key_listen, &mlx_st);
    mlx_hook(mlx_st.window, 17, (1L<<19), exit_cross,  &mlx_st);
    mlx_loop(mlx_st.mlx); 
	return (0);
}