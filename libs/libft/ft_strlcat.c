/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:35:58 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/11/05 18:20:35 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l;
	size_t	l2;

	i = 0;
	j = 0;
	l = ft_strlen(dest);
	l2 = ft_strlen(src);
	if (size < 1)
		return (l2);
	while (dest[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0' && i < size - 1)
		dest[i++] = src[j++];
	if (size >= l)
		dest[i] = '\0';
	if (size < l)
		return (l2 + size);
	else
		return (l2 + l);
}
