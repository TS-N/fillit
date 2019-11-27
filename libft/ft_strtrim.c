/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 23:55:27 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/06 01:51:34 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

unsigned int	ft_index_start(char const *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		++i;
	return (i);
}

unsigned int	ft_index_end(char const *s, unsigned int index_start)
{
	unsigned int	i;
	unsigned int	j;

	i = index_start;
	while (s[i])
	{
		j = 0;
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			while (s[i + j] == ' ' || s[i + j] == '\n'
					|| s[i + j] == '\t')
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

char			*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	index_start;
	unsigned int	index_end;
	char			*trimed;

	if (s == NULL)
		return (NULL);
	index_start = ft_index_start(s);
	index_end = ft_index_end(s, index_start);
	trimed = (char *)malloc(index_end - index_start + 1);
	i = -1;
	if (trimed == NULL)
		return (NULL);
	while (++i < index_end - index_start)
		trimed[i] = s[index_start + i];
	trimed[i] = '\0';
	return (trimed);
}
