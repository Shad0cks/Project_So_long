/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:35:50 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 02:40:31 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

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

int	renderer_next_frame(t_mlx *mlx_st)
{
	if (mlx_st->player->will_die == 1 || (mlx_st->count_item == 0
			&& mlx_st->player->want_exit))
		player_win(mlx_st);
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
			(map->max_y * 64), "So_long");
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
	refresh_map(&mlx_st);
	mlx_hook(mlx_st.window, 2, (1L << 13), key_listen, &mlx_st);
	mlx_hook(mlx_st.window, 17, (1L << 19), exit_cross, &mlx_st);
	mlx_loop_hook(mlx_st.mlx, renderer_next_frame, &mlx_st);
	mlx_loop(mlx_st.mlx);
	return (0);
}
