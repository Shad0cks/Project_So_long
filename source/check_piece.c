/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:33:15 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/10 05:33:38 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	check_piece_here(char **buffer, char c)
{
	int	y;

	y = 0;
	while (buffer[y] != NULL)
	{
		if (ft_strchr(buffer[y], c))
			return (1);
		y++;
	}
	return (0);
}

int	check_all_piece(char **buffer)
{
	int	i;
	int	y;

	y = 0;
	while (buffer[y] != NULL)
	{
		i = 0;
		while (buffer[y][i] != '\0')
		{
			if (buffer[y][i] != '1' && buffer[y][i] != '0'
					&& buffer[y][i] != 'P'
					&& buffer[y][i] != 'C' && buffer[y][i] != 'E'
					&& buffer[y][i] != 10)
				return (0);
			i++;
		}
		y++;
	}
	return (1);
}
