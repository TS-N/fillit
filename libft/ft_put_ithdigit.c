/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ithdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:35:23 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/07 20:33:03 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_ithdigit(long nb, unsigned int index)
{
	unsigned int	i;

	i = 0;
	while (++i != index)
		nb /= 10;
	ft_putchar(nb % 10 + '0');
	return ;
}
