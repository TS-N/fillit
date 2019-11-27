/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:12:00 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/06 01:51:34 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	i;

	i = -1;
	if (s == NULL)
		return (NULL);
	subs = ft_strnew(len);
	if (subs == NULL)
		return (NULL);
	while (++i < len)
		*(subs + i) = *(s + start + i);
	*(subs + i) = '\0';
	return (subs);
}
