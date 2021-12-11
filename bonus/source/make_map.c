/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 06:06:02 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 02:40:31 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	*put_image(t_mlx *mlx_st, void *img, int x, int y)
{
	int	width;
	int	height ;

	width = 64;
	height = 64;
	if (!img)
	{
		printf("sprite error");
		exit_func(&mlx_st);
	}
	mlx_put_image_to_window(mlx_st->mlx, mlx_st->window, img, x, y);
	return (NULL);
}

void	event_map(int y_b, int x_b, char c, t_mlx *mlx_st)
{
	if (c == 'P' && mlx_st->map_b[y_b][x_b] == 'P')
	{
		mlx_st->player->pos_x = x_b;
		mlx_st->player->pos_y = y_b;
	}
	if (c == 'C' && mlx_st->map_b[y_b][x_b] == 'C')
		mlx_st->count_item += 1;
}

void	put_sprite(t_mlx *mlx_st, char c, void *img)
{
	int	x_b;
	int	y_b;

	y_b = 0;
	if (c == 'C')
		mlx_st->count_item = 0;
	while (mlx_st->map_b[y_b] != NULL)
	{
		x_b = 0;
		while (mlx_st->map_b[y_b][x_b] != '\0')
		{
			if (mlx_st->map_b[y_b][x_b] == c || (c == '0'
				&& mlx_st->map_b[y_b][x_b] != '1'))
			{
				if (c == 'N')
					put_image(mlx_st, img, x_b * 64 + 10, y_b * 64 + 64);
				else
					put_image(mlx_st, img, x_b * 64, y_b * 64 + 64);
			}
			event_map(y_b, x_b, c, mlx_st);
			x_b++;
		}
		y_b++;
	}
}

void	refresh_map(t_mlx *mlx_st)
{
	char	*number;
	char	*string;

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
