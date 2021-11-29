/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:28:13 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/11/02 15:44:03 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned int	index;
	unsigned char	*result;

	result = (unsigned char *)pointer;
	index = 0;
	while (index < count)
	{
		result[index] = value;
		index++;
	}
	return ((void *)result);
}
