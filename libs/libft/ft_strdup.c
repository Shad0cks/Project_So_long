/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <pdeshaye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:12:23 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/12/11 02:07:05 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*cped;
	int		i;

	cped = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (cped == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		cped[i] = src[i];
		i++;
	}
	cped[i] = '\0';
	return (cped);
}
