/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 03:46:07 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/11 00:09:46 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fillit.h"

int		main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) >= 0)
		{
			fillit(fd);
			close(fd);
			return (0);
		}
		ft_putstr("error\n");
	}
	else
		ft_putstr("usage:\t./fillit [source_file]\n");
	return (0);
}
