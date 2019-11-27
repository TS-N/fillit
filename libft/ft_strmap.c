/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <tsaura-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 20:18:42 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/11/06 01:51:34 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*frsh;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	frsh = ft_strnew(ft_strlen(s));
	if (frsh == NULL)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(frsh + i) = (*f)(*(s + i));
		i++;
	}
	return (frsh);
}
