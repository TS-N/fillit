/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:10:48 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/07 19:56:19 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_flstdel(t_tet *alst)
{
	if (!alst)
		return ;
	if (alst->next)
		ft_flstdel((alst->next));
	free(alst);
	alst = NULL;
	return ;
}
