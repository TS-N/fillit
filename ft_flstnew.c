#include "fillit.h"

f_list		*ft_flstnew(char c, unsigned short pos)
{
	f_list		*link;

	link = (f_list *)ft_memalloc(sizeof(f_list));
	if (link == NULL)
		return (NULL);
	link->c = c;
    link->pos = pos;
	link->next = NULL;
	return (link);
}