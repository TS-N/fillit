#include "fillit.h"

int		exist_check(unsigned short tet)
{
	unsigned short	a[19];
	unsigned int	i;

	i = -1;
	a[0] = 0x4526;
	a[1] = 0x8159;
	a[2] = 0x0412;
	a[3] = 0x0159;
	a[4] = 0x0456;
	a[5] = 0x0126;
	a[6] = 0x0489;
	a[7] = 0x0481;
	a[8] = 0x0152;
	a[9] = 0x4156;
	a[10] = 0x4159;
	a[11] = 0x0485;
	a[12] = 0x4815;
	a[13] = 0x0459;
	a[14] = 0x4152;
	a[15] = 0x0156;
	a[16] = 0x0123;
	a[17] = 0x048c;
	a[18] = 0x0415;
	while (++i < 19)
		if (a[i] == tet)
			return (1);
	return (0);
}
int		valid_input(int fd, f_list **head)
{
	unsigned int		y;
	unsigned int		x;
	int					lstlen;
	char				*line;
	unsigned short		tet;
	f_list				*node;

	tet = 0;
	lstlen = 0;
	y = -1;
	while (get_next_line(fd, &line) > 0)
	{
		++y;
		if (y == 4)
		{
			y = -1;
			if (line[0] != '\0')
				return (-3);
			while (tet & 0xc000 && tet & 0xc00 && tet & 0xc0 && tet & 0xc)
				tet -= 0x4444;
			while (tet & 0x3000 && tet & 0x300 && tet & 0x30 && tet & 0x3)
				tet -= 0x1111;
			if (!exist_check(tet))
				return (-1);
			node = ft_flstnew(('A' + lstlen), tet);
			if (!node)
				return (0);
			tet = 0;
			ft_flstaddend(head, node);
			++lstlen;
		}
		else
		{
			x = 0;
			while (line[x])
			{
				if ((line[x] != '.' && line[x] != '#') || x > 3)
					return (-2); 
				if (line[x] == '#')
				{
					if (tet > 0x1000)
						return (-1);
					tet <<= 2;
					tet += x;
					tet <<= 2;
					tet += y;
				}
				++x;
			}
		}
		free (line);
	}
	while (tet & 0xc000 && tet & 0xc00 && tet & 0xc0 && tet & 0xc)
		tet -= 0x4444;
	while (tet & 0x3000 && tet & 0x300 && tet & 0x30 && tet & 0x3)
		tet -= 0x1111;
	if (!exist_check(tet))
		return (-5);
	node = ft_flstnew(('A' + lstlen), tet);
	if (!node)
		return (0);
	ft_flstaddend(head, node);
	++lstlen;
	return (lstlen);
}
