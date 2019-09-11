#include "fillit.h"

void        ft_flstreset(tet_list *tetro)
{
    //printf("before = %llx\n", *((unsigned long long *)tetro->tet));
    *((unsigned long long *)tetro->tet) = tetro->name->id;
    tetro->xi = 0;
    tetro->yi = 0;
}