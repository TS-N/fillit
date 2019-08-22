/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:11:09 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/06 22:24:01 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const char		*t1;
	const char		*t2;
	unsigned int	i;

	i = 0;
	t1 = s1;
	t2 = s2;
	while (t1[i] != '\0' || t2[i] != '\0')
	{
		if (t1[i] < t2[i])
			return ((unsigned char)t1[i] - (unsigned char)t2[i]);
		if (t1[i] > t2[i])
			return ((unsigned char)t1[i] - (unsigned char)t2[i]);
		i++;
	}
	return (0);
}
