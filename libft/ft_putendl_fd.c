/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 00:04:34 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/03 13:44:13 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char	nl;

	nl = '\n';
	if (s == NULL)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd(nl, fd);
}
