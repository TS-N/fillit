/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:07:53 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/07 19:56:23 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		r;

	if (!s1 || !s2)
		return (0);
	r = ft_strncmp(s1, s2, n);
	if (r == 0)
		return (1);
	else
		return (0);
}
