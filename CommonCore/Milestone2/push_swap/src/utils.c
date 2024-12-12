/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:57:22 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/12 10:02:15 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pop(t_stlist **head)
{
	t_stlist	*temp;
	int			popped_data;

	if (*head == NULL)
		return (-1);
	temp = *head;
	popped_data = temp->value;
	*head = (*head)->next;
	free(temp);
	return (popped_data);
}

void	push(t_stlist **head, int new_data)
{
	t_stlist	*new_node;

	new_node = (t_stlist *)malloc(sizeof(t_stlist));
	new_node->value = new_data;
	new_node->next = *head;
	*head = new_node;
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
