/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:15:51 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/07 16:12:31 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*node;

	node = *alst;
	if (node)
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
	else
		node = new;
	new->next = NULL;
	return ;
}
