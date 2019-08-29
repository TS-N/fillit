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

//char	redsize(short int mino)
//{



int		valid_input(int fd)
{
	char			*line;
	unsigned int	y;
	unsigned int	x;
	short int		pos;
	short int		mino;
	char			*tetros;

	pos = 0;
	mino = 0;
	y = 1;
	tetros = "\x5e\xea\x3d\x9d\xd6\xac\xe5\xf1\xba\x76\xad\xe9\x79\xcd\x7a\xb6\xf3\xf0\xda";
	//head = NULL;
	//node = head;
	while (get_next_line(fd, &line) > 0)
	{
		if (y % 5 == 0)
		{
			if (line[0] != '\0')
				return (1);
			printf("tetromino =%d\n", mino);
			mino = 0;

		}
		else
		{
			if (ft_strlen(line) != 4)
				return (1);
			x = 0;
			while (line[x])
			{
				if (line[x] != '.' && line[x] != '#')
					return (1); 
				mino = mino << 1;
				if (line[x] == '#')
					++mino;
				++x;
			}
		}
		free (line);
		++y;
	}
	printf("tetromino =%d\n", mino);

	return (1);
}

void	fillit(int fd)
{
	char	*line;
	int		ret;

	line = NULL;
	if ((ret = valid_input(fd)) == 1)
		ft_putstr("Valid input.\n");
	else
		printf("Invalid input.\nRet =%d\n", ret);
	return ;
}
