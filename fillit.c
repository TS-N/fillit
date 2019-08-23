/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:52:21 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/21 20:52:38 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_input(int fd)
{
	char	*line;
	int		i;

	i = 1;
	while (get_next_line(fd, &line) > 0);
	{
		if (i % 5 == 0)
			if (line[0] != '\0')
				return (0);
		else
		{
			if (ft_strlen(line) != 4)
				return (0);
			while (*line)
				if (*line != '.' && *line != '#')
					return (0);
		}
	}
	return (1);
}

void	fillit(int fd)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	return ;
}
