/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:01:03 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/06 01:51:34 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hayst;
	size_t	i;
	size_t	j;

	j = 0;
	hayst = (char *)haystack;
	if (ft_strlen(needle) == 0)
		return (hayst);
	while (hayst[j] != '\0' && j < len)
	{
		i = 0;
		while (needle[i] == hayst[j + i] && j + i < len)
		{
			i++;
			if (needle[i] == '\0')
				return (hayst + j);
		}
		j++;
	}
	return (NULL);
}
