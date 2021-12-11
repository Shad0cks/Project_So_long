/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:41:37 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 02:40:31 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	size_open(char *path)
{
	char	*line;
	int		fd;
	int		i;

	line = "";
	i = 0;
	fd = open(path, O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			i++;
		free(line);
	}
	close(fd);
	return (i);
}

char	**put_buffer(char *path)
{
	char	*line;
	int		fd;
	int		i;
	char	**buffer;

	i = 0;
	buffer = malloc(sizeof(char *) * (size_open(path) + 1));
	if (!buffer)
		return (NULL);
	fd = open(path, O_RDONLY);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		buffer[i] = line;
		i++;
	}
	close(fd);
	return (buffer);
}

void	cond1(t_mlx *mlx_st, int x, int y)
{
	if (mlx_st->map_b[y][x] == 'C')
		mlx_st->count_item--;
	else if (mlx_st->map_b[y][x] == 'E' && mlx_st->count_item == 0)
	{
		mlx_st->player->count_move++;
		mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
		mlx_st->player->want_exit = 1;
	}
}

void	cond2(t_mlx *mlx_st, int x, int y)
{
	if (mlx_st->map_b[y][x] == 'N')
	{
		mlx_st->player->count_move++;
		mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
		mlx_st->player->will_die = 1;
		refresh_map(mlx_st);
	}
	else if (mlx_st->map_b[y][x] != 'E')
	{
		mlx_st->player->count_move++;
		mlx_st->map_b[mlx_st->player->pos_y][mlx_st->player->pos_x] = '0';
		mlx_st->map_b[y][x] = 'P';
	}
}
