/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:52:21 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/09/11 05:26:25 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		inbound(tet_list *node, unsigned int s)
{
		if ((node->yi >= s && node->tet[0]) ||
			(1 + node->yi >= s && node->tet[1]) ||
			(2 + node->yi >= s && node->tet[2]) ||
			(3 + node->yi >= s && node->tet[3]))
		{
			ft_flstreset(node);
			return (0);
		}
	return (1);
}

int		overlap(unsigned short *grid, tet_list *node)
{
	unsigned int	i;

	i = -1;
	while (++i < 4)
		if ((grid[i + node->yi] & (node->tet[i])))
			return (0);
	return (1);
}

tet_list	*shift(tet_list *node, unsigned int rbound)
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

unsigned int		fillgrid(unsigned *s, tet_list **head, tet_list *node, \
														unsigned short *grd)
{
	unsigned short	grid[16];
	unsigned int	i;
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



void	fillit(int fd)
{
	int		ret;
	unsigned short	grid[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	tet_list	*head;
	tet_list	*node;
	unsigned int s;

	
	head = NULL;
	if ((ret = valid_input(fd, &head)) > 0)
	{
		s = mingridsize(ret);
		if ((s = fillgrid(&s, &head, head, grid)))
		{
			node = head;
			spitresult(&head,s);
			ft_flstdel(&head);
		}
	}
	else
		printf("Invalid input.\nRet =%d\n", ret);
	return ;
}
