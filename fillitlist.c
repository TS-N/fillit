/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:52:21 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/21 20:52:38 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

min_grid(int tetnb)
{
	int		len;

	len = 0;
	while((len * len) < (tetnb * 4))
		++len;
}

void	fillit(int fd)
{
	static f_list	*head;
	char			*line;
	int				ret;
	f_list 			*node;

	line = NULL;
	if ((ret = valid_input(fd, &head)) > 0)
	{
		node = head;
		min_grid(ret);
		/*while (node != NULL)
		{
			printf("pos =%u\nchar = %c\n", node->pos, node->c);
			node = node->next;
		}*/
	}
	else
		printf("Invalid input.\nRet =%d\n", ret);
	return ;
}
