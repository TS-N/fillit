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

int					inbound(t_tet *node, unsigned int s)
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

int					overlap(unsigned short *grid, t_tet *node)
{
	unsigned int	i;

	i = -1;
	while (++i < 4)
		if ((grid[i + node->yi] & (node->tet[i])))
			return (0);
	return (1);
}

t_tet				*shift(t_tet *n, int s)
{
	unsigned		ybuf;
	unsigned short	rbound;

	rbound = ~0;
	rbound = rbound >> s;
	if (((n->tet[0] >> 1) & rbound) || ((n->tet[1] >> 1) & rbound) || \
			((n->tet[2] >> 1) & rbound) || ((n->tet[3] >> 1) & rbound))
	{
		ybuf = n->yi;
		ft_flstreset(n);
		n->yi = ++ybuf;
	}
	else
	{
		*(unsigned long long *)(n->tet) = *(unsigned long long *)(n->tet) >> 1;
		++(n->xi);
	}
	return (n);
}

int					fillgrid(int *s, t_tet **head, t_tet *node, \
					unsigned short *grd)
{
	unsigned short	grid[16];

	if (!node)
		return (1);
	arcpy(grid, grd, *s, -1);
	while (inbound(node, *s))
	{
		if (overlap(grid, node))
		{
			impress(grid, node);
			if (fillgrid(s, head, node->next, grid))
				return (*s);
		}
		node = shift(node, *s);
		arcpy(grid, grd, *s, -1);
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
	t_tet			*head;
	t_tet			*node;

	head = NULL;
	ft_bzero(grid, 32);
	ret = 0;
	if ((ret = valid_input(fd, &head, &ret)) > 0)
	{
		ret = mingridsize(ret, &head);
		if ((ret = fillgrid(&ret, &head, head, grid)))
		{
			node = head;
			spitresult(&head, ret);
		}
	}
	else
		ft_putstr("error:\tinvalid file\n");
	ft_flstdel(head);
	return ;
}
