#include "fillit.h"

void	ft_flstaddend(tet_list **alst, tet_list *new)
{
	tet_list	*node;

	node = *alst;
	if (node)
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
	else
		*alst = new;
	new->next = NULL;
	return ;
}