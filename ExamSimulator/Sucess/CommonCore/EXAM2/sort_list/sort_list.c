#include "list.h"

void swap(t_list *a, t_list *b){
	int c = a->data;
	a->data = b->data;
	b->data = c;
}


t_list	*sort_list(t_list* lst, int (*cmp)(int, int)){
	int swapbool = 1;
	t_list *lista = lst;
	
	while(swapbool == 1){
		swapbool = 0;
		while (lista != 0 && lista->next != 0){
			if(cmp(lista->data, lista->next->data) == 0){
				swap(lista, lista->next);
				swapbool = 1;
			}
			lista = lista->next;
		}
		lista = lst;
	}
	return (lista);
}
