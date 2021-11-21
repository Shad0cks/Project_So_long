/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:11:49 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/11/05 18:16:36 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *str, char c)
{
	int		i;
	int		trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

char	**ft_split(char const *string, char charset)
{
	size_t		len;
	size_t		index;
	char		**split;

	index = 0;
	if (!string)
		return (NULL);
	split = malloc(((count_word(string, charset)) + 1) * sizeof(*split));
	if (split == NULL)
		return (NULL);
	while (*string != '\0')
	{
		while (*string && *string == charset)
			string++;
		len = 0;
		while (*string && *string != charset)
		{
			string++;
			len++;
		}
		if (*(string - 1) != charset)
			split[index++] = ft_substr(string - len, 0, len);
	}
	split[index] = 0;
	return (split);
}
