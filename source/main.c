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
	char *number;
	char *string;
	
	put_sprite(mlx_st, '0', mlx_st->map_sprite->sand);
    put_sprite(mlx_st, '1', mlx_st->map_sprite->wall);
    put_sprite(mlx_st, 'C', mlx_st->map_sprite->item);
    put_sprite(mlx_st, 'E', mlx_st->map_sprite->door);
    put_sprite(mlx_st, 'P', mlx_st->player->sprite_liste[0]);
	put_sprite(mlx_st, 'N', mlx_st->map_sprite->fire[6]);
	number = ft_itoa(mlx_st->player->count_move);
	if (mlx_st->player->will_die == 1)
		string = ft_strjoin("LOSE !! \t\t\t Player die in ", number);
	else if (mlx_st->player->want_exit == 0)
		string = ft_strjoin("MOVE COUNT : ", number);
	else
		string = ft_strjoin("WIN !! \t\t\t AFTER : ", number);
	mlx_string_put(mlx_st->mlx, mlx_st->window, 32, 32, 0x52e710, string);
	free(number);
	free(string);
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
	mlx_st->player->sprite_liste = malloc(sizeof(void *) * player_count_sprite + 1);
	width = 64;
	height = 64;
	while (i < player_count_sprite)
	{
		number = ft_itoa(i + 1);
		string = ft_strjoin("sprite/player/player", number);
		free(number);
		end = ft_strjoin(string , ".xpm");
		free(string);
		mlx_st->player->sprite_liste[i] = mlx_xpm_file_to_image(mlx_st->mlx, end, &width, &height);
		free(end);
		i++;
	}
	mlx_st->player->sprite_liste[i] = NULL;
}

void stock_sprite_enemy(mlx_t *mlx_st, int enemy_count_sprite)
{
	char *number;
	char *string;
	char *end;
	int i;
	int width;
	int height;

	i = enemy_count_sprite - 1;
	mlx_st->map_sprite->fire = malloc(sizeof(void *) * enemy_count_sprite + 1);
	width = 64;
	height = 64;
	while (i >= 0)
	{
		number = ft_itoa(i + 1);
		string = ft_strjoin("sprite/fire/fire", number);
		free(number);
		end = ft_strjoin(string , ".xpm");
		free(string);
		mlx_st->map_sprite->fire[i] = mlx_xpm_file_to_image(mlx_st->mlx, end, &width, &height);
		free(end);
		i--;
	}
	mlx_st->map_sprite->fire[i] = NULL;
}

void frame_enemy(mlx_t *mlx_st, int  index)
{
	int i;
	int y;

	y = 0;
    while (mlx_st->map_b[y] != NULL)
    {
        i = 0;
        while(mlx_st->map_b[y][i] != '\0')
        {
            if (mlx_st->map_b[y][i] == 'N')
                {
					mlx_put_image_to_window(mlx_st->mlx, mlx_st->window, mlx_st->map_sprite->sand, i * 64, y * 64 + 64);
					mlx_put_image_to_window(mlx_st->mlx, mlx_st->window, mlx_st->map_sprite->fire[index], i * 64 + 10, y * 64 + 64);
				}
            i++;
        }
        y++;
    }		
}

int renderer_next_frame(mlx_t *mlx_st)
{
	static int i = 0;
	static int y = 0;
	static int int_enemy = 0;

	if(int_enemy == 14)
		int_enemy = 0;
	if(i == 8)
		i = 0;
	if(y == 10000)
		y = 0;
	if (mlx_st->player->will_die == 1 || (mlx_st->count_item == 0 && mlx_st->player->want_exit))
		player_win(mlx_st);
	else if (y % 1000 == 0)
	{
		mlx_put_image_to_window(mlx_st->mlx, mlx_st->window, mlx_st->map_sprite->sand, mlx_st->player->pos_x * 64, mlx_st->player->pos_y * 64 + 64);
		mlx_put_image_to_window(mlx_st->mlx, mlx_st->window, mlx_st->player->sprite_liste[i], mlx_st->player->pos_x * 64, mlx_st->player->pos_y * 64 + 64);
		if(y % 2000 == 0)
			frame_enemy(mlx_st, int_enemy);
		i++;
	}
	y++;
	int_enemy++;
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
	mlx_st->window = mlx_new_window(mlx_st->mlx, map->max_x * 64, (map->max_y * 64) + 64, "So_long");
}

int main(void)
{
    map_t map;
	map_sprite_t map_sprite;
    player_t player;
	mlx_t mlx_st;
	char **buffer;

	buffer = put_buffer();
    init_player_struct(&player);
    map.max_x = -1;
    map.max_y = -1;
	check_main(buffer, &map);
	mlx_init_t(&mlx_st, &map, &map_sprite, &player);
	mlx_st.map_b = buffer;
	set_sprite(&mlx_st);
	stock_sprite_player(&mlx_st, 8);
	stock_sprite_enemy(&mlx_st, 14);
	refresh_map(&mlx_st);
	mlx_hook(mlx_st.window, 2, (1L<<13), key_listen, &mlx_st);
    mlx_hook(mlx_st.window, 17, (1L<<19), exit_cross,  &mlx_st);
	mlx_loop_hook(mlx_st.mlx, renderer_next_frame, &mlx_st);
    mlx_loop(mlx_st.mlx); 
	return (0);
}