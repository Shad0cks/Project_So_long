/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:34:37 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/11/05 12:38:52 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove( void *destination, const void *source, size_t size)
{
	const unsigned char	*cast_src;
	unsigned char		*cast_dest;
	unsigned int		i;

	cast_src = (const unsigned char *) source;
	cast_dest = (unsigned char *) destination;
	if (!destination && !source)
		return (NULL);
	i = 0;
	if (cast_src < cast_dest)
	{
		size++;
		while (i < --size)
			cast_dest[size - 1] = cast_src[size - 1];
	}
	else
	{
		while (i < size)
		{
			cast_dest[i] = cast_src[i];
			i++;
		}
	}
	return ((void *)cast_dest);
}
