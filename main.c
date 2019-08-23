#include "fillit.h"

int		main(int ac, char ** av)
{
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		fillit(fd);
	}
	else
		ft_putstr("usage:\t/.fillit [source_file]\n");
	return (0);
}
