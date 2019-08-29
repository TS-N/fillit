#include "fillit.h"

void	ft_flstaddend(f_list **alst, f_list *new)
{
	f_list	*node;

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