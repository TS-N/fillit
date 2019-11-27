/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 23:55:36 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/15 16:32:13 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

unsigned int	ft_index_start_c(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] && (s[i] == c))
		++i;
	return (i);
}

unsigned int	ft_index_end_c(char const *s, unsigned int index_start, char c)
{
	unsigned int	i;
	unsigned int	j;

	i = index_start;
	while (s[i])
	{
		j = 0;
		if (s[i] == c)
		{
			while (s[i + j] == c)
			{
				if (!s[i + j + 1])
					return (i);
				++j;
			}
			i += j;
		}
		else
			++i;
	}
	return (ft_strlen(s));
}

char			*ft_strtrim_char(char const *s, char c)
{
	unsigned int	i;
	unsigned int	index_start;
	unsigned int	index_end;
	char			*trimed;

	if (s == NULL)
		return (NULL);
	index_start = ft_index_start_c(s, c);
	index_end = ft_index_end_c(s, index_start, c);
	if (index_start == index_end)
		return (NULL);
	trimed = (char *)malloc(index_end - index_start + 1);
	i = -1;
	if (trimed == NULL)
		return (NULL);
	while (++i < index_end - index_start)
		trimed[i] = s[index_start + i];
	trimed[i] = '\0';
	return (trimed);
}
