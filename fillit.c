/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:52:21 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/29 23:20:29 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int mingridsize(int ret)
{
	unsigned int	s;

	s = 2;
	while (s * s < ret * 4)
		++s;
	return (s);
}

fillgrid(unsigned int s, t_list **head)
{
	unsigned short int	grid[s];
	unsigned int		i;
	t_list				*node;

	node = *head;
	i = 0;
	while (i < s)
	{
		if (grid[i] & )
	}
}

void	fillit(int fd)
{
	char	*line;
	int		ret;
	t_list	*head;
	t_list	*node;
	int i;
	char c;

	line = NULL;
	(void)c;
	(void)i;
	head = NULL;
	if ((ret = valid_input(fd, &head)) > 0)
	{
		printf("Valid input. RET = %i\n", ret);
		node = head;
		while (node)
		{
			i = 0;
			printf("0x%llx\n", (*((unsigned long long *)node->content)));
			/*while (i < 4)
			{
				printf("content[%d] = %u\np = %p\n", i,(((unsigned short *)node->content)[i]), &(((unsigned short *)node->content)[i]));
				++i;
			}
			c = 'A' + node->content_size; 
			printf("c = %c\n", c);*/
			node = node->next;
		}

	}
	else
		printf("Invalid input.\nRet =%d\n", ret);
		/*node = head;
		while (node)
		{
			i = 0;
			//printf("0x%llx\n", (*((unsigned long long *)node->content)));
			while (i < 4)
			{
				printf("content[%d] = %u\np = %p\n", i,(((unsigned short *)node->content)[i]), &(((unsigned short *)node->content)[i]));
				++i;
			}
			c = 'A' + node->content_size; 
			//printf("c = %c\n", c);
			node = node->next;
		}*/
	return ;
}
