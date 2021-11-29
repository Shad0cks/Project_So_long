/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:50:53 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/11/03 15:49:16 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*value;

	value = malloc(elementCount * elementSize);
	if (value == NULL)
		return (NULL);
	ft_bzero(value, elementCount * elementSize);
	return (value);
}
