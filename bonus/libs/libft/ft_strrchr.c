/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:18:35 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/11/03 15:44:23 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr( const char *string, int searchedChar)
{
	int	len;

	len = ft_strlen((char *)string);
	while (len >= 0)
	{
		if (string[len] == (char)searchedChar)
			return ((char *)string + len);
		len--;
	}
	return (NULL);
}
