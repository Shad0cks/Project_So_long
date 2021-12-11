/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:56:38 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 02:40:31 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	set_sprite(t_mlx *mlx_st)
{
	int	height;
	int	width;

	width = 64;
	height = 64;
	mlx_st->map_sprite->wall = mlx_xpm_file_to_image(mlx_st->mlx,
			"bonus/sprite/wall.xpm", &width, &height);
	mlx_st->map_sprite->sand = mlx_xpm_file_to_image(mlx_st->mlx,
			"bonus/sprite/sand.xpm", &width, &height);
	mlx_st->map_sprite->item = mlx_xpm_file_to_image(mlx_st->mlx,
			"bonus/sprite/item.xpm", &width, &height);
	mlx_st->map_sprite->door = mlx_xpm_file_to_image(mlx_st->mlx,
			"bonus/sprite/door.xpm", &width, &height);
	mlx_st->map_sprite->tomb = mlx_xpm_file_to_image(mlx_st->mlx,
			"bonus/sprite/tomb.xpm", &width, &height);
}

int	key_listen(int keycode, t_mlx *params)
{
	if (params->player->will_die == 1 || params->player->want_exit == 1)
		return (0);
	if (keycode == 53)
		exit_func(params);
	else if (keycode == 13)
		go_up(params);
	else if (keycode == 1)
		go_down(params);
	else if (keycode == 0)
		go_left(params);
	else if (keycode == 2)
		go_right(params);
	return (0);
}

void	check_main(char **buffer, t_map *map)
{
	if (!check_all_piece(buffer))
	{
		printf("Error\n no valid piece in map\n");
		free_map(buffer);
		exit(-1);
	}
	if (!check_piece_here(buffer, 'P') || !check_piece_here(buffer, 'E')
		|| !check_piece_here(buffer, 'C'))
	{
		printf("Error\n map piece error\n");
		free_map(buffer);
		exit(-1);
	}
	if (valid_map(buffer) <= 2 || calc_map_size(buffer, map) == -1
		|| check_close(buffer, map) == -1)
	{
		printf("Error\n map error\n");
		free_map(buffer);
		exit(-1);
	}
}

void	mlx_init_t(t_mlx *mlx_st, t_map *map,
		t_map_sprite *map_sprite, t_player *player)
{
	mlx_st->map_size = map;
	mlx_st->map_sprite = map_sprite;
	mlx_st->player = player;
	mlx_st->mlx = mlx_init();
	if (mlx_st->mlx == NULL)
		exit(-1);
	mlx_st->window = mlx_new_window(mlx_st->mlx, map->max_x * 64,
			(map->max_y * 64) + 64, "So_long");
}

int	main(int argc, char *argv[])
{
	t_map			map;
	t_map_sprite	map_sprite;
	t_player		player;
	t_mlx			mlx_st;
	char			**buffer;

	(void)argc;
	buffer = put_buffer(argv[1]);
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
	mlx_hook(mlx_st.window, 2, (1L << 13), key_listen, &mlx_st);
	mlx_hook(mlx_st.window, 17, (1L << 19), exit_cross, &mlx_st);
	mlx_loop_hook(mlx_st.mlx, renderer_next_frame, &mlx_st);
	mlx_loop(mlx_st.mlx);
	return (0);
}
