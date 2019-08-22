/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 02:38:59 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/07/27 22:48:12 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*chs;
	size_t			i;

	i = 0;
	chs = (unsigned char *)s;
	while (i < n)
	{
		if (*(chs + i) == (unsigned char)c)
			return (chs + i);
		i++;
	}
	return (0);
}
