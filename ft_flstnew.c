#include "fillit.h"

tet_list		*ft_flstnew(char c, unsigned short *tetro)
{
	tet_list		*link;

	link = (tet_list *)ft_memalloc(sizeof(tet_list));
	if (link == NULL)
		return (NULL);
	link->tet[0] = tetro[0];
	link->tet[1] = tetro[1];
	link->tet[2] = tetro[2];
	link->tet[3] = tetro[3];
	link->xi = 0;
    link->yi = 0;
	link->c = c;
	link->next = NULL;
	return (link);
}