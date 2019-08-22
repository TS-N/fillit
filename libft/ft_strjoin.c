/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:34:29 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/11 18:02:34 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*joins;

	if (!s1 || !s2)
		return (NULL);
	joins = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (joins == NULL)
		return (NULL);
	joins = ft_strcat(joins, s1);
	joins = ft_strcat(joins, s2);
	return (joins);
}
