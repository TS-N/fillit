/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 01:23:06 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/05 20:18:00 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_buf;
	unsigned char	*src_buf;
	size_t			i;

	dst_buf = (unsigned char *)dst;
	src_buf = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_buf[i] = src_buf[i];
		if (dst_buf[i] == (unsigned char)c)
			return ((void *)(dst_buf + i + 1));
		++i;
	}
	return (NULL);
}
