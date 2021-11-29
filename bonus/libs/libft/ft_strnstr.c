/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:52:37 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/11/03 14:34:13 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	j;

	j = 0;
	index = 0;
	if (!*little)
		return ((char *)big);
	while (big[index] != '\0' && (index + j) < len)
	{
		if (big[index + j] == little[j])
		{
			if (little[++j] == '\0')
				return ((char *)big + index);
			continue ;
		}
		j = 0;
		index++;
	}
	return (NULL);
}
