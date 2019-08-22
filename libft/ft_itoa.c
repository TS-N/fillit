/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 13:05:14 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/02 14:13:43 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	size_t			buf;
	unsigned int	i;
	char			*a;

	i = 1;
	buf = ft_intsize(n);
	a = ft_strnew(buf);
	if (a == NULL)
		return (NULL);
	a = ft_strset(a, '0', buf);
	if (n == -2147483648)
		*(a + buf - i++) = 8 + '0';
	if (n == -2147483648)
		n /= 10;
	if (n < 0)
		*a = '-';
	if (n < 0)
		n *= -1;
	while (n >= 1)
	{
		*(a + buf - i) = (n % 10) + '0';
		n /= 10;
		++i;
	}
	return (a);
}
