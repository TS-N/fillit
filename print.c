/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 05:37:28 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/11 00:09:47 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fillit.h"

void		gfill(t_tet *node, char grid[16][16])
{
	char		c;

	ft_bzero(grid, 16 * 16);
	while (node)
	{
		c = node->c;
		grid[node->name->y0 + node->yi][node->name->x0 + node->xi] = c;
		grid[node->name->y1 + node->yi][node->name->x1 + node->xi] = c;
		grid[node->name->y2 + node->yi][node->name->x2 + node->xi] = c;
		grid[node->name->y3 + node->yi][node->name->x3 + node->xi] = c;
		node = node->next;
	}
	return ;
}

void		spitresult(t_tet **head, unsigned int s)
{
	t_tet			*node;
	unsigned int	i;
	unsigned int	j;
	char			grid[16][16];

	node = *head;
	gfill(*head, grid);
	i = 0;
	while (i < s)
	{
		j = 0;
		while (j < s)
		{
			grid[i][j] ? ft_putchar(grid[i][j]) : ft_putchar('.');
			++j;
		}
		ft_putchar('\n');
		++i;
	}
	return ;
}
