/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flstaddend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 04:11:52 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/10 23:57:48 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fillit.h"

void		ft_flstaddend(t_tet **alst, t_tet *new)
{
	t_tet	*node;

	node = *alst;
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
	else
		*alst = new;
	new->next = NULL;
	return ;
}
