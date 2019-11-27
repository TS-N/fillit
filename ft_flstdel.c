/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:10:48 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/11 00:10:06 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fillit.h"

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
