/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 03:37:09 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/11 00:09:42 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fillit.h"

t_tet		*ft_flstnew(char c, unsigned short *tetro)
{
	t_tet		*link;

	link = (t_tet *)ft_memalloc(sizeof(t_tet));
	if (link == NULL)
		return (NULL);
	link->tet[0] = tetro[0];
	link->tet[1] = tetro[1];
	link->tet[2] = tetro[2];
	link->tet[3] = tetro[3];
	link->xi = 0;
	link->yi = 0;
	link->c = c;
	link->next = NULL;
	return (link);
}
