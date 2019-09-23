/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:52:21 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/09/12 04:27:44 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					inbound(tet_list *node, unsigned int s)
{
	if ((node->yi >= s && node->tet[0]) || \
		(1 + node->yi >= s && node->tet[1]) || \
		(2 + node->yi >= s && node->tet[2]) || \
		(3 + node->yi >= s && node->tet[3]))
	{
		ft_flstreset(node);
		return (0);
	}
	return (1);
}

int					overlap(unsigned short *grid, tet_list *node)
{
	unsigned int	i;

	i = -1;
	while (++i < 4)
		if ((grid[i + node->yi] & (node->tet[i])))
			return (0);
	return (1);
}

tet_list			*shift(tet_list *node, unsigned int rbound)
{
	unsigned		ybuf;

	if (((node->tet[0] >> 1) & rbound) || ((node->tet[1] >> 1) & rbound) || \
			((node->tet[2] >> 1) & rbound) || ((node->tet[3] >> 1) & rbound))
	{
		ybuf = node->yi;
		ft_flstreset(node);
		node->yi = ++ybuf;
	}
	else
	{
		*(unsigned long long *)(node->tet) = *(unsigned long long *)(node->tet) >> 1;
		++(node->xi);
	}
	return (node);
}

int		fillgrid(int *s, tet_list **head, tet_list *node, \
								unsigned short *grd)
{
	unsigned short	grid[16];
	int				i;
	unsigned short	rbound;

	if (!node)
		return (1);
	i = -1;
	while (++i < *s)
		grid[i] = grd[i];
	rbound = ~0;
	rbound = rbound >> *s;
	while (inbound(node, *s))
	{
		if (overlap(grid, node))
		{
			impress(grid, node);
			if (fillgrid(s, head, node->next, grid))
				return (*s);
		}
		node = shift(node, rbound);
		i = -1;
		while (++i < *s)
			grid[i] = grd[i];
	}
	ft_flstreset(node);
	if (node->c == 'A')
	{
		++(*s);
		fillgrid(s, head, node, grid);
		return (*s);
	}
	return (0);
}

void				fillit(int fd)
{
	int				ret;
	unsigned short	grid[16];
	tet_list		*head;
	tet_list		*node;


	head = NULL;
	ft_bzero(grid, 32);
	if ((ret = valid_input(fd, &head)) > 0)
	{
		if ((ret = fillgrid(&ret, &head, head, grid)))
		{
			node = head;
			spitresult(&head, ret);
			ft_flstdel(head);
		}
	}
	else
	{
		ft_flstdel(head);
		ft_putstr("error:\tinvalid file\n");
	}
	return ;
}