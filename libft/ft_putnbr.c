/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 23:48:30 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/06 01:51:34 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr(int n)
{
	unsigned int	i;
	size_t			len;
	long int		nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	len = ft_intsize(nb);
	if (nb == 2147483648)
		--len;
	i = -1;
	while (++i < len)
		ft_put_ithdigit(nb, len - i);
	return ;
}
