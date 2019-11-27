/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:29:29 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/06 01:51:34 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char			*hayst;
	unsigned int	i;

	hayst = (char *)haystack;
	if (ft_strlen(needle) == 0)
		return (hayst);
	while (*hayst != '\0')
	{
		i = 0;
		while (needle[i] == hayst[i])
		{
			i++;
			if (needle[i] == '\0')
				return (hayst);
		}
		hayst++;
	}
	return (NULL);
}
