/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:57:22 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/12 11:37:55 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stlist **head, int new_data)
{
    t_stlist	*new_node;
    t_stlist	*last;

    new_node = (t_stlist *)malloc(sizeof(t_stlist));
    new_node->value = new_data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    last = *head;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

int	stack_size(t_stlist *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

void	free_stack(t_stlist **head)
{
	t_stlist	*temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
