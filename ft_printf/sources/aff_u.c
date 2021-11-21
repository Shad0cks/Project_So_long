/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:43:01 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/11/12 01:43:01 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	int_count(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb / 10)
	{
		count++;
		nb /= 10;
	}
	return (count + 1);
}

void	ft_itoa_unsiged(unsigned int nb, int *count)
{
	char			*result;
	int				index;

	index = int_count(nb);
	result = malloc(sizeof(char) * int_count(nb) + 1);
	if (result == NULL)
		return ;
	result[index] = '\0';
	while (nb / 10)
	{
		result[index - 1] = (nb % 10) + '0';
		index--;
		nb /= 10;
	}
	result[index - 1] = (nb % 10) + '0';
	ft_putstr(result, count);
	free(result);
	result = NULL;
}
