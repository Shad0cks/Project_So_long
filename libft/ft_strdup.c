/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:12:23 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/11/05 18:16:41 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*cped;
	int	i;

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
