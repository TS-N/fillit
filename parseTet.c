/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseTet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:57:59 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/09/02 19:58:33 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//BUG WITH 2 '\n' AT THE END

unsigned long long	valid[19] = { \
									0x8000c0004, \
									0x8000800080008, \
									0xf, \
									0x2000e, \
									0xe0002, \
									0xc00080008, \
									0xc00040004, \
									0xe0008, \
									0x8000e, \
									0xc0006, \
									0x6000c, \
									0xc000c, \
									0x4000c0008, \
									0x40004000c, \
									0x80008000c, \
									0x4000e, \
									0xe0004, \
									0x8000c0008, \
									0x4000c0004 \
								};

int		tetrIsvalid(unsigned long long tet)
{
	unsigned int		i;

	i = 0;
	while (i < 19)
	{
		if (valid[i] == tet)
			return (1);
		++i;
	}
	return (0);
}

int		formncmp(unsigned short	tet[4], unsigned int ret, t_list **head)
{
	t_list		*node;

	if (!(tet[0] || tet[1] || tet[2] || tet[3]))
		return (-98);
	while (!(tet[0] & 0x8) && !(tet[1] & 0x8) && !(tet[2] & 0x8) \
			&& !(tet[3] & 0x8))
	{
		tet[0] = tet[0] << 1;
		tet[1] = tet[1] << 1;
		tet[2] = tet[2] << 1;
		tet[3] = tet[3] << 1;
	}
	while (!(tet[0]))
	{
		tet[0] = tet[1];
		tet[1] = tet[2];
		tet[2] = tet[3];
		tet[3] = 0;
	}
	node = ft_lstnew(tet, 8);
	node->content_size = ret;
	ft_lstaddend(head, node);
	if (tetrIsvalid(*((unsigned long long *)node->content)) == 0)
	{
		return (0);
		//ft_lstdel(head);
	}
	return (1);
}

int		valid_input(int fd, t_list **head)
{
	char			*line;
	unsigned int	i;
	unsigned int	j;
	unsigned int	y;
	unsigned int	x;
	unsigned int 	ret;
	unsigned short	tet[4] = {0, 0, 0, 0};

	i = 0;
	j = 0;
	y = 1;
	ret = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (y % 5 == 0)
		{
			if (line[0] || !(*(unsigned long long *)tet))
				return (-99);
			if (!(formncmp(tet, ret, head)))
			{
				return (-7);
			}
			tet[0] = 0;
			tet[1] = 0;
			tet[2] = 0;
			tet[3] = 0;
			++ret;
			i = 0;
			++j;
		}
		else
		{
			x = 0;
			if (ft_strlen(line) != 4)
				return (-9);
			while (x < 4)
			{
				if ((line[x] != '.' && line[x] != '#'))
					return (1);
				tet[i] = tet[i] << 1;
				if (line[x] == '#')
					++tet[i];
				++x;
			}
			++i;
		}
		free(line);
		++y;
	}
	if (!(formncmp(tet, ret, head)))
	{
		return (-73);
	}
	else
		++ret;
	return (ret);
}
