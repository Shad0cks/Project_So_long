/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 01:45:51 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 02:40:31 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	player_win(t_mlx *mlx_st)
{
	static int	i = 0;

	if (i == 9999)
		exit_func(mlx_st);
	i++;
}

void	set_sprite(t_mlx *mlx_st)
{
	int	height;
	int	width;

	width = 64;
	height = 64;
	mlx_st->map_sprite->wall = mlx_xpm_file_to_image(mlx_st->mlx,
			"sprite/wall.xpm", &width, &height);
	mlx_st->map_sprite->sand = mlx_xpm_file_to_image(mlx_st->mlx,
			"sprite/sand.xpm", &width, &height);
	mlx_st->map_sprite->item = mlx_xpm_file_to_image(mlx_st->mlx,
			"sprite/item.xpm", &width, &height);
	mlx_st->map_sprite->door = mlx_xpm_file_to_image(mlx_st->mlx,
			"sprite/door.xpm", &width, &height);
	mlx_st->player->sprite = mlx_xpm_file_to_image(mlx_st->mlx,
			"sprite/player.xpm", &width, &height);
}

void	free_map(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != NULL)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer[i]);
}

void	exit_func(void *params)
{
	t_mlx	*mlx_st;

	mlx_st = (t_mlx *)params;
	free_map(mlx_st->map_b);
	exit(0);
}

int	exit_cross(int keycode, void *params)
{
	(void)keycode;
	(void)params;
	exit(0);
	return (0);
}
