/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsetet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:57:59 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/09/12 04:22:11 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

struct f_list	f18 = {0x4000c0004000, 0, 1, 1, 0, 1, 1, 1, 2, NULL};
struct f_list	f17 = {0x8000c0008000, 0, 0, 0, 1, 1, 1, 0, 2, &f18};
struct f_list	f16 = {0xe0004000, 0, 1, 1, 0, 1, 1, 2, 1, &f17};
struct f_list	f15 = {0x4000e000, 0, 0, 1, 0, 2, 0, 1, 1, &f16};
struct f_list	f14 = {0x80008000c000, 0, 0, 1, 0, 0, 1, 0, 2, &f15};
struct f_list	f13 = {0x40004000c000, 0, 0, 1, 0, 1, 1, 1, 2, &f14};
struct f_list	f12 = {0x4000c0008000, 0, 0, 0, 1, 1, 1, 1, 2, &f13};
struct f_list	f11 = {0xc000c000, 0, 0, 0, 1, 1, 0, 1, 1, &f12};
struct f_list	f10 = {0x6000c000, 0, 0, 1, 0, 1, 1, 2, 1, &f11};
struct f_list	f9 = {0xc0006000, 0, 1, 1, 0, 1, 1, 2, 0, &f10};
struct f_list	f8 = {0x8000e000, 0, 0, 0, 1, 1, 0, 2, 0, &f9};
struct f_list	f7 = {0xe0008000, 0, 0, 0, 1, 1, 1, 2, 1, &f8};
struct f_list	f6 = {0xc00040004000, 1, 0, 1, 1, 1, 2, 0, 2, &f7};
struct f_list	f5 = {0xc00080008000, 0, 0, 0, 1, 0, 2, 1, 2, &f6};
struct f_list	f4 = {0xe0002000, 0, 1, 1, 1, 2, 1, 2, 0, &f5};
struct f_list	f3 = {0x2000e000, 0, 0, 1, 0, 2, 0, 2, 1, &f4};
struct f_list	f2 = {0xf000, 0, 0, 1, 0, 2, 0, 3, 0, &f3};
struct f_list	f1 = {0x8000800080008000, 0, 0, 0, 1, 0, 2, 0, 3, &f2};
struct f_list	f0 = {0x8000c0004000, 1, 0, 0, 1, 1, 1, 0, 2, &f1};
 
int		tetrisvalid(tet_list *ltet)
{
	struct		f_list		*node;

	node = &f0;
	while (node)
	{
		if (node->id == *((unsigned long long *)ltet->tet))
		{
			ltet->name = node;
			return (1);
		}
		node = node->next;
	}
	return (0);
}

int		formncmp(unsigned short tet[4], unsigned int ret, tet_list **head)
{
	tet_list		*node;

	if (!(tet[0] || tet[1] || tet[2] || tet[3]))
		return (-1);
	while (!(tet[0] & 0x8000) && !(tet[1] & 0x8000) && !(tet[2] & 0x8000) \
			&& !(tet[3] & 0x8000))
		*(unsigned long long *)tet = *(unsigned long long *)tet << 1;
	while (!(tet[0]))
		*(unsigned long long *)tet = *(unsigned long long *)tet >> 16;
	node = ft_flstnew((ret + 'A'), tet);
	ft_flstaddend(head, node);
	if (!tetrisvalid(node))
		return (0);
	return (1);
}

int		err(char *line, unsigned short *tet, tet_list **head, int ret)
{
	int		i;

	if (ret <= 0)
	{
		i = -1;
		if (ft_strlen(line) != 4)
		{
			free(line);
			return (-1);
		}
		while (++i < 4)
		{
			(*tet) = (*tet) << 1;
			if (line[i] == '#')
					++(*tet);
			else if ((line[i] != '.'))
			{
				free(line);
				return (-2);
			}	
		}
	}
	else
	{
		if ((line[0] || !(*(unsigned long long *)tet) )|| \
			!(formncmp(tet, ret - 1, head)) || ret > 26)
		{
			free(line);
			return (-3);
		}
	}
	return (0);
}

int		valid_input(int fd, tet_list **head)
{
	char			*line;
	unsigned int	i;
	unsigned int	y;
	int				ret;
	unsigned short	tet[4];
	int sup;

	i = 0;
	y = 1;
	ret = 0;
	ft_bzero(tet, 8);
	while (get_next_line(fd, &line) > 0)
	{
		if (y % 5 == 0)
		{
			if ((sup = err(line, tet, head, ret + 1)) < 0)
				return (sup);
			*(unsigned long long *)tet = 0;
			i = 0;
			++ret;
		}
		else
		{
			if ((sup = err(line, (tet + i), head, -ret)) < 0)
				return (sup);
			++i;
		}
		free(line);
		++y;
	}
	if ((y - 1) % 5 == 0)
		return (-1);
	(!(formncmp(tet, ret + 1 , head))) ? (ret = -1) : ++ret;
	ret = mingridsize(ret, head);
	return (ret);
}
