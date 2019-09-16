/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 05:37:28 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/09/12 03:53:17 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		spitresult(tet_list **head, unsigned int s)
{
	tet_list		*node;
	unsigned int	i;
	unsigned int	j;
	char			grid[s][s];
	char			c;

	node = *head;
	ft_bzero(grid, s * s);
	while (node)
	{
		c = node->c;
		grid[node->name->y0 + node->yi][node->name->x0 + node->xi] = c;
		grid[node->name->y1 + node->yi][node->name->x1 + node->xi] = c;
		grid[node->name->y2 + node->yi][node->name->x2 + node->xi] = c;
		grid[node->name->y3 + node->yi][node->name->x3 + node->xi] = c;
		node = node->next;
	}
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
	if (node)
		ft_putchar('\n');
}
