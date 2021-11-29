#include "../include/header.h"

void player_win(mlx_t *mlx_st)
{
	static int i = 0;
	if (i == 9999)
		exit_func(mlx_st);
	i++;
}

void set_sprite(mlx_t *mlx_st)
{
	int height;
	int width;

	width = 64;
	height = 64;

	mlx_st->map_sprite->wall = mlx_xpm_file_to_image(mlx_st->mlx, "sprite/wall.xpm", &width, &height);
	mlx_st->map_sprite->sand = mlx_xpm_file_to_image(mlx_st->mlx, "sprite/sand.xpm", &width, &height);
	mlx_st->map_sprite->item = mlx_xpm_file_to_image(mlx_st->mlx, "sprite/item.xpm", &width, &height);
	mlx_st->map_sprite->door = mlx_xpm_file_to_image(mlx_st->mlx, "sprite/door.xpm", &width, &height);
	mlx_st->map_sprite->tomb = mlx_xpm_file_to_image(mlx_st->mlx, "sprite/tomb.xpm", &width, &height);
	mlx_st->player->sprite = mlx_xpm_file_to_image(mlx_st->mlx, "sprite/player.xpm", &width, &height);

}

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

int key_listen(int keycode, mlx_t* params)
{

	if (params->player->will_die == 1 || params->player->want_exit == 1)
		return (0);
    if (keycode == 53)
        exit_func(params);
    else if (keycode == 13)
        go_up(params);
	else if	(keycode == 1)
		go_down(params);
	else if (keycode == 0)
		go_left(params);
	else if (keycode == 2)
		go_right(params);
		
    return (0);
}

void refresh_map(mlx_t *mlx_st)
{	
	put_sprite(mlx_st, '0', mlx_st->map_sprite->sand);
    put_sprite(mlx_st, '1', mlx_st->map_sprite->wall);
    put_sprite(mlx_st, 'C', mlx_st->map_sprite->item);
    put_sprite(mlx_st, 'E', mlx_st->map_sprite->door);
    put_sprite(mlx_st, 'P', mlx_st->player->sprite);
	printf("Player move : %d\n", mlx_st->player->count_move);
}

int renderer_next_frame(mlx_t *mlx_st)
{
	if (mlx_st->player->will_die == 1 || (mlx_st->count_item == 0 && mlx_st->player->want_exit))
		player_win(mlx_st);
	return (0);
}

void check_main(char **buffer, map_t *map)
{
	if(!check_all_piece(buffer))
    {
        printf("Error\n no valid piece in map\n");
        free_map(buffer);
		exit(-1);
    }
    if (!check_piece_here(buffer, 'P') || !check_piece_here(buffer, 'E') || !check_piece_here(buffer, 'C'))
    {
        printf("Error\n map piece error\n");
		free_map(buffer);
        exit(-1);
    }
	if(valid_map(buffer) <= 2 || calc_map_size(buffer, map) == -1 || check_close(buffer, map) == -1)
    {
        printf("Error\n map error\n");
		free_map(buffer);
        exit(-1);
    }
}

void mlx_init_t(mlx_t *mlx_st, map_t *map, map_sprite_t *map_sprite, player_t *player)
{
	mlx_st->map_size = map;
	mlx_st->map_sprite = map_sprite;
    mlx_st->player = player;
    mlx_st->mlx = mlx_init();
    if (mlx_st->mlx == NULL)
        exit(-1);
	mlx_st->window = mlx_new_window(mlx_st->mlx, map->max_x * 64, (map->max_y * 64), "So_long");
}

int main(int argc, char *argv[])
{
    map_t map;
	map_sprite_t map_sprite;
    player_t player;
	mlx_t mlx_st;
	char **buffer;

	(void)argc;
	buffer = put_buffer(argv[1]);
    init_player_struct(&player);
    map.max_x = -1;
    map.max_y = -1;
	check_main(buffer, &map);
	mlx_init_t(&mlx_st, &map, &map_sprite, &player);
	mlx_st.map_b = buffer;
	set_sprite(&mlx_st);
	refresh_map(&mlx_st);
	mlx_hook(mlx_st.window, 2, (1L<<13), key_listen, &mlx_st);
    mlx_hook(mlx_st.window, 17, (1L<<19), exit_cross,  &mlx_st);
	mlx_loop_hook(mlx_st.mlx, renderer_next_frame, &mlx_st);
    mlx_loop(mlx_st.mlx); 
	return (0);
}