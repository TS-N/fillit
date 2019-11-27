/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:48:29 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/06 01:51:34 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_intlen(int n)
{
	size_t	len;
	long	nb;

	nb = n;
	len = 0;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (10);
	if (nb < 0)
		nb *= -1;
	while (nb >= 1)
	{
		nb /= 10;
		++len;
	}
	return (len);
}
