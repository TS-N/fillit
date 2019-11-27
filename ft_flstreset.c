/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flstreset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 03:33:47 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/11 00:09:44 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fillit.h"

void	ft_flstreset(t_tet *tetro)
{
	*((unsigned long long *)tetro->tet) = tetro->name->id;
	tetro->xi = 0;
	tetro->yi = 0;
	return ;
}
