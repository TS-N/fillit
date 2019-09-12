#include "fillit.h"

int		main(int ac, char ** av)
{
	int		fd;

	if (ac == 2)
	{
		if((fd = open(av[1], O_RDONLY)) >= 0)
		{
			fillit(fd);
			return (0);
		}
	}
	ft_putstr("usage:\t/.fillit [source_file]\n");
	return (0);
}
