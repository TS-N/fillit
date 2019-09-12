#include "fillit.h"

unsigned int mingridsize(int ret)
{
	unsigned int	limit;

	limit = 2;
	while (limit * limit < (unsigned int)ret * 4)
		++limit;
	return (limit);
}

void	impress(unsigned short *grid, tet_list *node)
{
		unsigned short	y;

		y = node->yi;
		grid[0 + y] = grid[0 + y] | (node->tet[0]);
		grid[1 + y] = grid[1 + y] | (node->tet[1]);
		grid[2 + y] = grid[2 + y] | (node->tet[2]);
		grid[3 + y] = grid[3 + y] | (node->tet[3]);
}