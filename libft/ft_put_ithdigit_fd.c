/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ithdigit_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:37:35 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/06 20:38:04 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_ithdigit_fd(long nb, unsigned int index, int fd)
{
	unsigned int	i;

	i = 0;
	while (++i != index)
		nb /= 10;
	ft_putchar_fd(nb % 10 + '0', fd);
	return ;
}
