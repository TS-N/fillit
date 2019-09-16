/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flstaddend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 04:11:52 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/09/12 04:12:22 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_flstaddend(tet_list **alst, tet_list *new)
{
	tet_list	*node;

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
