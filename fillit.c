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
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

void spitresult(tet_list **head, unsigned int s);


int		inbound(tet_list *node, unsigned int s)
{
	unsigned short i;

	i = 0;
	while (i < 4)
	{
		if (i + node->yi >= s && node->tet[i])
		{
			ft_flstreset(node);
			return (0);
		}
		++i;
	}
	return (1);
}

int		overlap(unsigned short *grid, tet_list *node)
{
	unsigned int	i;

	i = 0;
	while (i < 4)
	{
		if ((grid[i + node->yi] & (node->tet[i])))
			return (0);
		//printBits(2, (grid) + i);
		//printf("grid[%u] = %x\n", i + node->yi, grid[i + node->yi]);
		++i;
	}
	return (1);
}

void	impress(unsigned short *grid, tet_list *node)
{
	unsigned	i;

	i = 0;
	while (i < 4)
	{
		grid[i + node->yi] = grid[i + node->yi] | (node->tet[i]);
		++i;
	}
	/*i = 0;
	while (i < s + 3)
	{
		printBits(2, grid + i++);
	}
	printf("\n");
	spitresult(head, s + 3);*/
}

tet_list	*shift(tet_list *node, unsigned int rbound)
{
	unsigned		ybuf;


	//printBits(2, &rbound);
	//printf("before AA = %llx\n", *((unsigned long long *)node->tet));
	if (((node->tet[0] >> 1) & rbound) || ((node->tet[1] >> 1) & rbound) || ((node->tet[2] >> 1) & rbound) || ((node->tet[3] >> 1) & rbound))
	{
		ybuf = node->yi;
		ft_flstreset(node);
		node->yi = ++ybuf;

	}
	else
	{
		*(unsigned long long *)(node->tet) = *(unsigned long long *)(node->tet) >> 1;
		++(node->xi);
	}
	//printf("afterAA = %llx\n", *((unsigned long long *)node->tet));

	return (node);
}

unsigned int		fillgrid(unsigned int *s, tet_list **head, tet_list *node, unsigned short *grd)
{
	unsigned short grid[19];
	int i;
	unsigned short	rbound;


	if (!node)
		return (1);
	i = 0;
	while (i < 19)
	{
		grid[i] = grd[i];
		++i;
	}
	rbound = ~0;
	rbound = rbound >> *s;
	while (inbound(node, *s))
	{
		if (overlap(grid, node))
		{
			impress(grid, node);
			if (fillgrid(s, head, node->next, grid))
				return (*s);
		}
		node = shift(node, rbound);
				i = 0;
		while (i < 19)
		{
			grid[i] = grd[i];
			++i;
		}
	}
	ft_flstreset(node);
	if (node->c == 'A')
	{
		++(*s);
		fillgrid(s, head, node, grid);
		return (*s);
	}
	return (0);
}

void spitresult(tet_list **head, unsigned int s)
{
	tet_list		*node;
	unsigned int i;
	unsigned int j;
	char			cgrid[16][16] = {{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}, \
						{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}, {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}, 
						{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
						{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
						{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
						{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
						{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
						{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
						{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}}; 
	node = *head;
	while (node)
	{
		cgrid[node->name->y0 + node->yi][node->name->x0 + node->xi] = node->c;
		cgrid[node->name->y1 + node->yi][node->name->x1 + node->xi] = node->c;
		cgrid[node->name->y2 + node->yi][node->name->x2 + node->xi] = node->c;
		cgrid[node->name->y3 + node->yi][node->name->x3 + node->xi] = node->c;
		node = node->next;
	}
	i = 0;
	while (i < s)
	{
		j = 0;
		while (j < s)
		{
			ft_putchar(cgrid[i][j]);
			++j;
		}
		ft_putchar('\n');
		++i;
	}
	ft_putchar('\n');
}

void	fillit(int fd)
{
	int		ret;
	unsigned short	grid[19] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	tet_list	*head;
	tet_list	*node;
	unsigned int s;


	head = NULL;
	if ((ret = valid_input(fd, &head)) > 0)
	{
		printf("Valid input. RET = %i\n", ret);
		s = mingridsize(ret);
		printf("s= %u\n", ret);
		if ((s = fillgrid(&s, &head, head, grid)))
		{
			printf("There is a solution\nS = %u\n", s);
			node = head;
			spitresult(&head,s);

		}
/*		while (node)
		{
			i = 0;
			printf("0x%llx\n", (*((unsigned long long *)node->tet)));
			while (i < 4)
			{
				printf("content[%d] = %u\n", i,((node->tet)[i]));
				++i;
			}
			printf("AAAA = %llx", node->name->id);
			printf("c = %c\n", node->c); 
			node = node->next;
		}*/

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
