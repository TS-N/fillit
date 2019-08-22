/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 22:28:54 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/01 00:08:41 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_buf;
	const unsigned char	*src_buf;
	size_t				i;

	dst_buf = (unsigned char *)dst;
	src_buf = (unsigned char *)src;
	i = 0;
	if (dst_buf < src_buf)
		while (i < len)
		{
			*(dst_buf + i) = *(src_buf + i);
			++i;
		}
	else if (src_buf < dst_buf)
		while (++i <= len)
			*(dst_buf + len - i) = *(src_buf + len - i);
	return (dst);
}
