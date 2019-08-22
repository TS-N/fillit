/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:38:54 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/07 20:54:24 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;
	size_t			len;
	long int		nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	len = ft_intsize(nb);
	if (nb == 2147483648)
		--len;
	i = -1;
	while (++i < len)
		ft_put_ithdigit_fd(nb, len - i, fd);
	return ;
}
