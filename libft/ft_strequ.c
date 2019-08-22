/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:02:42 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/06 22:14:15 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	int		r;

	if (s1 == NULL || s2 == NULL)
		return (0);
	r = ft_strcmp(s1, s2);
	if (r == 0)
		return (1);
	else
		return (0);
}
