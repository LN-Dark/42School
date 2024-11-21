#include "list.h"

void	swap_values(t_list *a, t_list *b)
{
	int swap = a->data;
	a->data = b->data;
	b->data = swap;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int)){
	int swap = 1;
	t_list *lista = lst;
	
	while(swap == 1)
	{
		swap = 0;
		while (lista != 0 && lista->next != 0)
		{
			if(cmp(lista->data, lista->next->data) == 0)
			{
				swap_values(lista, lista->next);
				swap = 1;
			}
			lista = lista->next;
		}
		lista = lst;
	}
	return(lst);
}
