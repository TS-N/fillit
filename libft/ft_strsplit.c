/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 23:23:29 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/06 01:51:34 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**a;
	size_t	i;

	i = 0;
	if (!s || !(a = (char **)ft_memalloc(sizeof(char *) * (ft_wcnt(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s == c)
			while (*s == c)
				++s;
		if (*s != c && *s)
		{
			if (!(a[i] = (char *)ft_memalloc(ft_wlen(s, c) + 1)))
			{
				free(a);
				return (NULL);
			}
			ft_strncpy(a[i], s, ft_wlen(s, c));
			a[i++][ft_wlen(s, c)] = '\0';
			s += (ft_wlen(s, c));
		}
	}
	a[i] = NULL;
	return (a);
}
