/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:25:43 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 02:40:31 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	go_up(t_mlx *mlx_st)
{
	mlx_clear_window(mlx_st->mlx, mlx_st->window);
	if (mlx_st->map_b[mlx_st->player->pos_y - 1][mlx_st->player->pos_x] &&
			mlx_st->map_b[mlx_st->player->pos_y - 1][mlx_st->player->pos_x]
			!= '1')
	{
		cond1(mlx_st, mlx_st->player->pos_x, mlx_st->player->pos_y - 1);
		cond2(mlx_st, mlx_st->player->pos_x, mlx_st->player->pos_y - 1);
	}
	if (mlx_st->player->will_die == 0)
		refresh_map(mlx_st);
	return (1);
}

int	go_down(t_mlx *mlx_st)
{
	mlx_clear_window(mlx_st->mlx, mlx_st->window);
	if (mlx_st->map_b[mlx_st->player->pos_y + 1][mlx_st->player->pos_x] &&
			mlx_st->map_b[mlx_st->player->pos_y + 1][mlx_st->player->pos_x]
			!= '1')
	{
		cond1(mlx_st, mlx_st->player->pos_x, mlx_st->player->pos_y + 1);
		cond2(mlx_st, mlx_st->player->pos_x, mlx_st->player->pos_y + 1);
	}
	if (mlx_st->player->will_die == 0)
		refresh_map(mlx_st);
	return (1);
}

int	go_left(t_mlx *mlx_st)
{
	mlx_clear_window(mlx_st->mlx, mlx_st->window);
	if (mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x - 1] &&
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x - 1]
			!= '1')
	{
		cond1(mlx_st, mlx_st->player->pos_x - 1, mlx_st->player->pos_y);
		cond2(mlx_st, mlx_st->player->pos_x - 1, mlx_st->player->pos_y);
	}
	if (mlx_st->player->will_die == 0)
		refresh_map(mlx_st);
	return (1);
}

int	go_right(t_mlx *mlx_st)
{
	mlx_clear_window(mlx_st->mlx, mlx_st->window);
	if (mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x + 1] &&
			mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x + 1]
			!= '1')
	{
		cond1(mlx_st, mlx_st->player->pos_x + 1, mlx_st->player->pos_y);
		cond2(mlx_st, mlx_st->player->pos_x + 1, mlx_st->player->pos_y);
	}
	if (mlx_st->player->will_die == 0)
		refresh_map(mlx_st);
	return (1);
}
