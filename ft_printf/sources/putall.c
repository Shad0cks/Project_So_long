/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:47:09 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/11/12 01:48:02 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	int_count_n(int nb)
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

void	ft_putnbr(int nb, int *count)
{
	ft_putnbr_fd(nb, 1);
	if (nb < 0)
		*count += 1;
	*count += int_count_n(nb);
}

void	ft_putchar(int c, int *count)
{
	ft_putchar_fd(c, 1);
	*count += 1;
}

void	ft_putstr(char *str, int *count)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		*count += 6;
		return ;
	}
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
}
