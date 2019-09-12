/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flstreset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 03:33:47 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/09/12 03:36:32 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_flstreset(tet_list *tetro)
{
	*((unsigned long long *)tetro->tet) = tetro->name->id;
	tetro->xi = 0;
	tetro->yi = 0;
	return ;
}
