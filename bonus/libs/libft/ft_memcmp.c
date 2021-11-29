/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:52:33 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/11/03 15:46:16 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*cast_str1;
	const unsigned char	*cast_str2;

	cast_str1 = (const unsigned char *)str1;
	cast_str2 = (const unsigned char *)str2;
	if (str1 == str2 || n == 0)
		return (0);
	while (n > 0)
	{
		if (*cast_str1 != *cast_str2)
			return ((*cast_str1) - (*cast_str2));
		cast_str1++;
		cast_str2++;
		n--;
	}
	return (0);
}
