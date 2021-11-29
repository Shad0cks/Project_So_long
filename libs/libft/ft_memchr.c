/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:42:07 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/11/05 11:30:44 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*cast_string;

	cast_string = (unsigned char *) str;
	while (n > 0)
	{
		if (*cast_string == (unsigned char)c)
			return (cast_string);
		cast_string++;
		n--;
	}
	return (NULL);
}
