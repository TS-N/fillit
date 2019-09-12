/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 03:46:07 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/09/12 03:48:19 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) >= 0)
		{
			fillit(fd);
			return (0);
		}
		close(fd);
	}
	ft_putstr("usage:\t/.fillit [source_file]\n");
	return (0);
}
