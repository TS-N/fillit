/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 21:50:26 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/01 00:43:14 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*buf1;
	unsigned char	*buf2;

	i = 0;
	buf1 = (unsigned char *)s1;
	buf2 = (unsigned char *)s2;
	while (i < n)
	{
		if (*(buf1 + i) > *(buf2 + i) || *(buf1 + i) < *(buf2 + i))
			return (*(buf1 + i) - *(buf2 + i));
		i++;
	}
	return (0);
}
