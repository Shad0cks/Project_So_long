/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:27:37 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 02:40:31 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

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

void	player_win(t_mlx *mlx_st)
{
	static int	i = 0;

	if (i == 9999)
		exit_func(mlx_st);
	i++;
}
