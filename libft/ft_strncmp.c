/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:46:52 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/06 01:51:34 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	const char		*t1;
	const char		*t2;
	unsigned int	i;

	i = 0;
	t1 = s1;
	t2 = s2;
	while (i < (unsigned int)len && (t1[i] != '\0' || t2[i] != '\0'))
	{
		if (t1[i] < t2[i])
			return ((unsigned char)t1[i] - (unsigned char)t2[i]);
		if (t1[i] > t2[i])
			return ((unsigned char)t1[i] - (unsigned char)t2[i]);
		i++;
	}
	return (0);
}
