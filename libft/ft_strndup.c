/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:26:34 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/13 01:56:25 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;

	dup = (char *)ft_memalloc(n + 1);
	if (!dup)
		return (NULL);
	ft_strncpy(dup, s, n);
	return (dup);
}
