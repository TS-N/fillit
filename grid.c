#include "fillit.h"

unsigned int mingridsize(int ret)
{
	unsigned int	limit;

	limit = 2;
	while (limit * limit < (unsigned int)ret * 4)
		++limit;
	return (limit);
}