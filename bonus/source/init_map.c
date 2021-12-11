/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:55:14 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 02:39:29 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	strcount(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int	valid_map(char **buffer)
{
	int	count;
	int	y;

	y = 0;
	count = 0;
	while (buffer[y] != NULL)
	{
		count++;
		y++;
	}
	return (count);
}

int	calc_map_size(char **buffer, t_map *map)
{
	int	count;
	int	y;

	y = 0;
	count = 0;
	while (buffer[y] != NULL)
	{
		if (strcount(buffer[y]) != map->max_x && map->max_x != -1)
			return (-1);
		if (map->max_x == -1)
			map->max_x = strcount(buffer[y]);
		count++;
		y++;
	}
	map->max_y = count;
	if (map->max_x == map->max_y)
		return (-1);
	return (0);
}

static int	check_full_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_close(char **buffer, t_map *map)
{
	int	y;

	y = 0;
	while (buffer[y] != NULL)
	{
		if (y == 0 || y == map->max_y)
			if (check_full_wall(buffer[y]) == -1)
				return (-1);
		if ((buffer[y][0] != '1' || buffer[y][map->max_x - 1] != '1'))
			return (-1);
		y++;
	}
	return (0);
}
