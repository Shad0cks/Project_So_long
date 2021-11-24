#include "../include/header.h"

void set_sprite(mlx_t *mlx_st)
{
	int height;
	int width;

	width = 50;
	height = 50;

	mlx_st->map_sprite->wall = mlx_xpm_file_to_image(mlx_st->mlx, "../sprite/wall.xpm", &width, &height);
	mlx_st->map_sprite->sand = mlx_xpm_file_to_image(mlx_st->mlx, "../sprite/sand.xpm", &width, &height);
	mlx_st->map_sprite->item = mlx_xpm_file_to_image(mlx_st->mlx, "../sprite/item.xpm", &width, &height);
	mlx_st->map_sprite->door = mlx_xpm_file_to_image(mlx_st->mlx, "../sprite/door.xpm", &width, &height);
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
int no_enter(int keycode, void* params)
{
		(void)keycode;
	((mlx_t *)params)->player->is_running = 0;
    return (0);
}
int key_listen(int keycode, void* params)
{
	
    //ft_printf("keycode : %d\n", keycode);
    if (keycode == 53)
        exit_func(params);
    if (keycode == 13)
        go_up(params);
	if	(keycode == 1)
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
	
	put_sprite(mlx_st, '0', mlx_st->map_sprite->sand);
    put_sprite(mlx_st, '1', mlx_st->map_sprite->wall);
    put_sprite(mlx_st, 'C', mlx_st->map_sprite->item);
    put_sprite(mlx_st, 'E', mlx_st->map_sprite->door);
    put_sprite(mlx_st, 'P', mlx_st->player->sprite_liste[0]);
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

void stock_sprite_player(mlx_t *mlx_st, int player_count_sprite)
{
	char *number;
	char *string;
	char *end;
	int i;
	int width;
	int height;

	i = 0;
	mlx_st->player->sprite_liste = malloc(sizeof(void *) * 8 + 1);
	width = 40;
	height = 40;
	(void)mlx_st;
	while (i < player_count_sprite)
	{
		number = ft_itoa(i + 1);
		string = ft_strjoin("../sprite/player/player", number);
		free(number);
		end = ft_strjoin(string , ".xpm");
		free(string);
		mlx_st->player->sprite_liste[i] = mlx_xpm_file_to_image(mlx_st->mlx, end, &width, &height);
		free(end);
		i++;
	}
	mlx_st->player->sprite_liste[i] = NULL;
}

int renderer_next_frame(mlx_t *mlx_st)
{
	(void)mlx_st;
	static int i = 0;
	static int y = 0;
	if(i == 6)
		i = 0;
	if(y == 10000)
		y = 0;
	if (y % 5000 == 0)
	{
		mlx_put_image_to_window(mlx_st->mlx, mlx_st->window, mlx_st->map_sprite->sand, mlx_st->player->pos_x * 50, mlx_st->player->pos_y * 50);
		mlx_put_image_to_window(mlx_st->mlx, mlx_st->window, mlx_st->player->sprite_liste[i], mlx_st->player->pos_x * 50, mlx_st->player->pos_y * 50);
		i++;
	}

	y++;
	return (0);
}

int main(void)
{
    map_t map;
	map_sprite_t map_sprite;
    player_t player;
	char **buffer;
	buffer = put_buffer();
    init_player_struct(&player);
    map.max_x = -1;
    map.max_y = -1;
	if(!check_all_piece(buffer))
    {
        ft_printf("Error\n no valid piece in map\n");
        free_map(buffer);
		exit(-1);
    }
    if (!check_piece_here(buffer, 'P') || !check_piece_here(buffer, 'E') || !check_piece_here(buffer, 'C'))
    {
        ft_printf("Error\n map piece error\n");
		free_map(buffer);
        exit(-1);
    }
	if(valid_map(buffer) <= 2 || calc_map_size(buffer, &map) == -1 || check_close(buffer, &map) == -1)
    {
        ft_printf("Error\n map error\n");
		free_map(buffer);
        exit(-1);
    }
    mlx_t mlx_st;
	mlx_st.map_sprite = &map_sprite;
    mlx_st.player = &player;
    mlx_st.mlx = mlx_init();
    if (mlx_st.mlx == NULL)
        exit(-1);
	mlx_st.window = mlx_new_window(mlx_st.mlx, map.max_x * 50, map.max_y * 50, "So_long");
	mlx_st.map_b = buffer;
	set_sprite(&mlx_st);
	stock_sprite_player(&mlx_st, 6);
	refresh_map(&mlx_st);

	mlx_hook(mlx_st.window, 2, (1L<<13), key_listen, &mlx_st);
    mlx_hook(mlx_st.window, 17, (1L<<19), exit_cross,  &mlx_st);
	mlx_loop_hook(mlx_st.mlx, renderer_next_frame, &mlx_st);
    mlx_loop(mlx_st.mlx); 
	return (0);
}