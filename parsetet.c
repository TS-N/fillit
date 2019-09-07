/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsetet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:57:59 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/09/02 19:58:33 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//BUG WITH 2 '\n' AT THE END

f_list  f18 = {0x4000c0004, 0, 1, 1, 0, 1, 1, 1, 2, NULL};
f_list  f17 = {0x8000c0008, 0, 0, 0, 1, 1, 1, 0, 2, &f18};
f_list  f16 = {0xe0004, 0, 1, 1, 0, 1, 1, 2, 1, &f17};
f_list  f15 = {0x4000e, 0, 0, 1, 0, 2, 0, 1, 1, &f16};
f_list  f14 = {0x80008000c, 0, 0, 1, 0, 0, 1, 0, 2, &f15};
f_list  f13 = {0x40004000c, 0, 0, 1, 0, 1, 1, 1, 2, &f14};
f_list  f12 = {0x4000c0008, 0, 0, 0, 1, 1, 1, 1, 2, &f13};
f_list  f11 = {0xc000c, 0, 0, 0, 1, 1, 0, 1, 1, &f12};
f_list  f10 = {0x6000c, 0, 0, 1, 0, 1, 1, 2, 1, &f11};
f_list  f9 = {0xc0006, 0, 1, 1, 0, 1, 1, 2, 0, &f10};
f_list  f8 = {0x8000e, 0, 0, 0, 1, 1, 0, 2, 0, &f9};
f_list  f7 = {0xe0008, 0, 0, 0, 1, 1, 1, 2, 1, &f8};
f_list  f6 = {0xc00040004, 1, 0, 1, 1, 1, 2, 0, 2, &f7};
f_list  f5 = {0xc00080008, 0, 0, 0, 1, 0, 2, 1, 2, &f6};
f_list  f4 = {0xe0002, 0, 1, 1, 1, 2, 1, 2, 0, &f5};
f_list  f3 = {0x2000e, 0, 0, 1, 0, 2, 0, 2, 1, &f4};
f_list  f2 = {0xf, 0, 0, 1, 0, 2, 0, 3, 0, &f3};
f_list  f1 = {0x8000800080008, 0, 0, 0, 1, 0, 2, 0, 3, &f2};
f_list  f0 = {0x8000c0004, 1, 0, 0, 1, 1, 1, 0, 2, &f1};

int		tetrIsvalid(unsigned long long tet)
{
	f_list				*node;

	node = &f0;
	while (node)
	{
		if (node->id == tet)
			return (1);
		node = node->next;
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
	unsigned short	tet[4];

	i = 0;
	j = 0;
	y = 1;
	ret = 0;
	ft_bzero(tet, 8);
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