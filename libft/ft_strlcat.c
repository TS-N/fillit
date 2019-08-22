/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:35:50 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/03 13:41:37 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (dst[i] && i < size)
		++i;
	j = i;
	while (i + 1 < size && src[i - j])
	{
		dst[i] = src[i - j];
		++i;
	}
	if (j < size)
		dst[i] = '\0';
	return (j + ft_strlen(src));
}
