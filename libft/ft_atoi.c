/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:26:48 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/06 01:51:34 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_atoi(const char *str)
{
	long long int	nb;
	long long int	sign;

	sign = 1;
	nb = 0;
	while (*str == '\n' || *str == '\t' || *str == ' ' || *str == '\r'
			|| *str == '\v' || *str == '\f')
		str++;
	if (str[0] == '-')
	{
		str++;
		sign = -1;
	}
	else if (str[0] == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		nb = (nb * 10) + (*str - 48);
		str++;
	}
	return ((int)(nb * sign));
}
