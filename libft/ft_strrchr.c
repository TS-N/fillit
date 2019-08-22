/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:47:18 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/07/26 11:36:55 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*source;
	char			*buf;

	buf = NULL;
	source = (char *)s;
	i = 0;
	while (*source != '\0')
	{
		if ((int)*source == c)
			buf = source;
		source++;
		if ((int)*source == c)
			buf = source;
	}
	return (buf);
}
