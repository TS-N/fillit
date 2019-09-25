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

void		tynorm(unsigned short grid[16], unsigned short *grd, int s, int i)
{
	while (++i < s)
		grid[i] = grd[i];
}

int			mingridsize(int ret, t_tet **head)
{
	int					limit;
	t_tet				*node;

	node = *head;
	limit = 2;
	if (ret < 0)
		return (-1);
	while (limit * limit < ret * 4)
		++limit;
	return (limit);
}

void		impress(unsigned short *grid, t_tet *node)
{
	unsigned short	y;

	y = node->yi;
	grid[0 + y] = grid[0 + y] | (node->tet[0]);
	grid[1 + y] = grid[1 + y] | (node->tet[1]);
	grid[2 + y] = grid[2 + y] | (node->tet[2]);
	grid[3 + y] = grid[3 + y] | (node->tet[3]);
}
