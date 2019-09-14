/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 03:33:18 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/09/12 03:45:30 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int	mingridsize(unsigned int ret, tet_list **head)
{
	unsigned int		limit;
	tet_list			*node;

	node = *head;
	limit = 2;
	while (limit * limit < ret * 4)
		++limit;
/* 	while (node->next)
	{
		if ((*head)->name != node->next->name || \
			*((unsigned long long *)(*head)->tet) == 0xf000)
			return (limit);
		node = node->next;
	}*/
	return (limit);
}

void			impress(unsigned short *grid, tet_list *node)
{
	unsigned short	y;

	y = node->yi;
	grid[0 + y] = grid[0 + y] | (node->tet[0]);
	grid[1 + y] = grid[1 + y] | (node->tet[1]);
	grid[2 + y] = grid[2 + y] | (node->tet[2]);
	grid[3 + y] = grid[3 + y] | (node->tet[3]);
}
