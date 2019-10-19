/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 03:33:18 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/10/18 18:20:00 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		arcpy(unsigned short grid[16], unsigned short *grd, int s, int i)
{
	while (++i < s)
		grid[i] = grd[i];
}

int			mingridsize(int ret, t_tet **head)
{
	int					l;
	t_tet				*n;

	n = *head;
	l = 2;
	if (ret == 1)
	{
		if (*(unsigned long long *)n->tet == 0x4000e000)
			l = 3;
		else
			l = n->name->x3 > n->name->y3 ? n->name->x3 + 1 : n->name->y3 + 1;
	}
	else
	{
		while (l * l < ret * 4)
			++l;
	}
	while (n)
	{
		if (n->name->id != 0xc000c000 || l * l == ret * 4)
			return (l);
		n = n->next;
	}
	return (l + 1);
}

void		impress(unsigned short *grid, t_tet *n)
{
	unsigned short	y;

	y = n->yi;
	grid[0 + y] = grid[0 + y] | (n->tet[0]);
	grid[1 + y] = grid[1 + y] | (n->tet[1]);
	grid[2 + y] = grid[2 + y] | (n->tet[2]);
	grid[3 + y] = grid[3 + y] | (n->tet[3]);
}
